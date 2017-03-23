//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:18分:10秒  
// ><文件     ><  vli_decoder.c  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\deps\lzma\liblzma\common  
// ><隶属工程><   obs-studio  
// ><当前用户 ><  Administrator  
// ><作者     ><  Open Broadcaster Software   
// ><出处     >< 《 https://obsproject.com/ 》  
// ><目的     >< 【】  
// ><设计技术 ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////迭代修改///////////////////////////////////////////////////////  
// ><作者     ><  xzm  
// ><修改日期 ><  2017年:03月:21日   18时:18分:10秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       vli_decoder.c
/// \brief      Decodes variable-length integers
//
//  Author:     Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "common.h"


extern LZMA_API(lzma_ret)
lzma_vli_decode(lzma_vli *restrict vli, size_t *vli_pos,
		const uint8_t *restrict in, size_t *restrict in_pos,
		size_t in_size)
{
	// If we haven't been given vli_pos, work in single-call mode.
	size_t vli_pos_internal = 0;
	if (vli_pos == NULL) {
		vli_pos = &vli_pos_internal;
		*vli = 0;

		// If there's no input, use LZMA_DATA_ERROR. This way it is
		// easy to decode VLIs from buffers that have known size,
		// and get the correct error code in case the buffer is
		// too short.
		if (*in_pos >= in_size)
			return LZMA_DATA_ERROR;

	} else {
		// Initialize *vli when starting to decode a new integer.
		if (*vli_pos == 0)
			*vli = 0;

		// Validate the arguments.
		if (*vli_pos >= LZMA_VLI_BYTES_MAX
				|| (*vli >> (*vli_pos * 7)) != 0)
			return LZMA_PROG_ERROR;;

		if (*in_pos >= in_size)
			return LZMA_BUF_ERROR;
	}

	do {
		// Read the next byte. Use a temporary variable so that we
		// can update *in_pos immediately.
		const uint8_t byte = in[*in_pos];
		++*in_pos;

		// Add the newly read byte to *vli.
		*vli += (lzma_vli)(byte & 0x7F) << (*vli_pos * 7);
		++*vli_pos;

		// Check if this is the last byte of a multibyte integer.
		if ((byte & 0x80) == 0) {
			// We don't allow using variable-length integers as
			// padding i.e. the encoding must use the most the
			// compact form.
			if (byte == 0x00 && *vli_pos > 1)
				return LZMA_DATA_ERROR;

			return vli_pos == &vli_pos_internal
					? LZMA_OK : LZMA_STREAM_END;
		}

		// There is at least one more byte coming. If we have already
		// read maximum number of bytes, the integer is considered
		// corrupt.
		//
		// If we need bigger integers in future, old versions liblzma
		// will confusingly indicate the file being corrupt istead of
		// unsupported. I suppose it's still better this way, because
		// in the foreseeable future (writing this in 2008) the only
		// reason why files would appear having over 63-bit integers
		// is that the files are simply corrupt.
		if (*vli_pos == LZMA_VLI_BYTES_MAX)
			return LZMA_DATA_ERROR;

	} while (*in_pos < in_size);

	return vli_pos == &vli_pos_internal ? LZMA_DATA_ERROR : LZMA_OK;
}
