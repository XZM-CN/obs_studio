//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:14分:40秒  
// ><文件     ><  filter_flags_decoder.c  
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
// ><修改日期 ><  2017年:03月:21日   18时:14分:40秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       filter_flags_decoder.c
/// \brief      Decodes a Filter Flags field
//
//  Author:     Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "filter_decoder.h"


extern LZMA_API(lzma_ret)
lzma_filter_flags_decode(
		lzma_filter *filter, lzma_allocator *allocator,
		const uint8_t *in, size_t *in_pos, size_t in_size)
{
	// Set the pointer to NULL so the caller can always safely free it.
	filter->options = NULL;

	// Filter ID
	return_if_error(lzma_vli_decode(&filter->id, NULL,
			in, in_pos, in_size));

	if (filter->id >= LZMA_FILTER_RESERVED_START)
		return LZMA_DATA_ERROR;

	// Size of Properties
	lzma_vli props_size;
	return_if_error(lzma_vli_decode(&props_size, NULL,
			in, in_pos, in_size));

	// Filter Properties
	if (in_size - *in_pos < props_size)
		return LZMA_DATA_ERROR;

	const lzma_ret ret = lzma_properties_decode(
			filter, allocator, in + *in_pos, props_size);

	*in_pos += props_size;

	return ret;
}
