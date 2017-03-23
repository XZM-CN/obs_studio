//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:17分:04秒  
// ><文件     ><  simple_decoder.c  
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
// ><修改日期 ><  2017年:03月:21日   18时:17分:04秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       simple_decoder.c
/// \brief      Properties decoder for simple filters
//
//  Author:     Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "simple_decoder.h"


extern lzma_ret
lzma_simple_props_decode(void **options, lzma_allocator *allocator,
		const uint8_t *props, size_t props_size)
{
	if (props_size == 0)
		return LZMA_OK;

	if (props_size != 4)
		return LZMA_OPTIONS_ERROR;

	lzma_options_bcj *opt = lzma_alloc(
			sizeof(lzma_options_bcj), allocator);
	if (opt == NULL)
		return LZMA_MEM_ERROR;

	opt->start_offset = unaligned_read32le(props);

	// Don't leave an options structure allocated if start_offset is zero.
	if (opt->start_offset == 0)
		lzma_free(opt, allocator);
	else
		*options = opt;

	return LZMA_OK;
}
