//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   18ʱ:17��:09��  
// ><�ļ�     ><  simple_encoder.c  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\deps\lzma\liblzma\simple  
// ><��������><   obs-studio  
// ><��ǰ�û� ><  Administrator  
// ><����     ><  Open Broadcaster Software   
// ><����     >< �� https://obsproject.com/ ��  
// ><Ŀ��     >< ����  
// ><��Ƽ��� ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////�����޸�///////////////////////////////////////////////////////  
// ><����     ><  xzm  
// ><�޸����� ><  2017��:03��:21��   18ʱ:17��:09��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       simple_encoder.c
/// \brief      Properties encoder for simple filters
//
//  Author:     Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "simple_encoder.h"


extern lzma_ret
lzma_simple_props_size(uint32_t *size, const void *options)
{
	const lzma_options_bcj *const opt = options;
	*size = (opt == NULL || opt->start_offset == 0) ? 0 : 4;
	return LZMA_OK;
}


extern lzma_ret
lzma_simple_props_encode(const void *options, uint8_t *out)
{
	const lzma_options_bcj *const opt = options;

	// The default start offset is zero, so we don't need to store any
	// options unless the start offset is non-zero.
	if (opt == NULL || opt->start_offset == 0)
		return LZMA_OK;

	unaligned_write32le(out, opt->start_offset);

	return LZMA_OK;
}
