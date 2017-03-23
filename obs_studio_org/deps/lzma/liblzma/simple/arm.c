//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:11分:13秒  
// ><文件     ><  arm.c  
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
// ><修改日期 ><  2017年:03月:21日   18时:11分:13秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       arm.c
/// \brief      Filter for ARM binaries
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
arm_code(lzma_simple *simple lzma_attribute((__unused__)),
		uint32_t now_pos, bool is_encoder,
		uint8_t *buffer, size_t size)
{
	size_t i;
	for (i = 0; i + 4 <= size; i += 4) {
		if (buffer[i + 3] == 0xEB) {
			uint32_t src = (buffer[i + 2] << 16)
					| (buffer[i + 1] << 8)
					| (buffer[i + 0]);
			src <<= 2;

			uint32_t dest;
			if (is_encoder)
				dest = now_pos + (uint32_t)(i) + 8 + src;
			else
				dest = src - (now_pos + (uint32_t)(i) + 8);

			dest >>= 2;
			buffer[i + 2] = (dest >> 16);
			buffer[i + 1] = (dest >> 8);
			buffer[i + 0] = dest;
		}
	}

	return i;
}


static lzma_ret
arm_coder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters, bool is_encoder)
{
	return lzma_simple_coder_init(next, allocator, filters,
			&arm_code, 0, 4, 4, is_encoder);
}


extern lzma_ret
lzma_simple_arm_encoder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters)
{
	return arm_coder_init(next, allocator, filters, true);
}


extern lzma_ret
lzma_simple_arm_decoder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters)
{
	return arm_coder_init(next, allocator, filters, false);
}
