//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:16分:42秒  
// ><文件     ><  powerpc.c  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\deps\lzma\liblzma\simple  
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
// ><修改日期 ><  2017年:03月:21日   18时:16分:42秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       powerpc.c
/// \brief      Filter for PowerPC (big endian) binaries
///
//  Authors:    Igor Pavlov
//              Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "simple_private.h"


static size_t
powerpc_code(lzma_simple *simple lzma_attribute((__unused__)),
		uint32_t now_pos, bool is_encoder,
		uint8_t *buffer, size_t size)
{
	size_t i;
	for (i = 0; i + 4 <= size; i += 4) {
		// PowerPC branch 6(48) 24(Offset) 1(Abs) 1(Link)
		if ((buffer[i] >> 2) == 0x12
				&& ((buffer[i + 3] & 3) == 1)) {

			const uint32_t src = ((buffer[i + 0] & 3) << 24)
					| (buffer[i + 1] << 16)
					| (buffer[i + 2] << 8)
					| (buffer[i + 3] & (~3));

			uint32_t dest;
			if (is_encoder)
				dest = now_pos + (uint32_t)(i) + src;
			else
				dest = src - (now_pos + (uint32_t)(i));

			buffer[i + 0] = 0x48 | ((dest >> 24) &  0x03);
			buffer[i + 1] = (dest >> 16);
			buffer[i + 2] = (dest >> 8);
			buffer[i + 3] &= 0x03;
			buffer[i + 3] |= dest;
		}
	}

	return i;
}


static lzma_ret
powerpc_coder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters, bool is_encoder)
{
	return lzma_simple_coder_init(next, allocator, filters,
			&powerpc_code, 0, 4, 4, is_encoder);
}


extern lzma_ret
lzma_simple_powerpc_encoder_init(lzma_next_coder *next,
		lzma_allocator *allocator, const lzma_filter_info *filters)
{
	return powerpc_coder_init(next, allocator, filters, true);
}


extern lzma_ret
lzma_simple_powerpc_decoder_init(lzma_next_coder *next,
		lzma_allocator *allocator, const lzma_filter_info *filters)
{
	return powerpc_coder_init(next, allocator, filters, false);
}
