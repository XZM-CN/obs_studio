//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   18ʱ:14��:49��  
// ><�ļ�     ><  filter_flags_encoder.c  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\deps\lzma\liblzma\common  
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
// ><�޸����� ><  2017��:03��:21��   18ʱ:14��:49��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       filter_flags_encoder.c
/// \brief      Decodes a Filter Flags field
//
//  Author:     Lasse Collin
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "filter_encoder.h"


extern LZMA_API(lzma_ret)
lzma_filter_flags_size(uint32_t *size, const lzma_filter *filter)
{
	if (filter->id >= LZMA_FILTER_RESERVED_START)
		return LZMA_PROG_ERROR;

	return_if_error(lzma_properties_size(size, filter));

	*size += lzma_vli_size(filter->id) + lzma_vli_size(*size);

	return LZMA_OK;
}


extern LZMA_API(lzma_ret)
lzma_filter_flags_encode(const lzma_filter *filter,
		uint8_t *out, size_t *out_pos, size_t out_size)
{
	// Filter ID
	if (filter->id >= LZMA_FILTER_RESERVED_START)
		return LZMA_PROG_ERROR;

	return_if_error(lzma_vli_encode(filter->id, NULL,
			out, out_pos, out_size));

	// Size of Properties
	uint32_t props_size;
	return_if_error(lzma_properties_size(&props_size, filter));
	return_if_error(lzma_vli_encode(props_size, NULL,
			out, out_pos, out_size));

	// Filter Properties
	if (out_size - *out_pos < props_size)
		return LZMA_PROG_ERROR;

	return_if_error(lzma_properties_encode(filter, out + *out_pos));

	*out_pos += props_size;

	return LZMA_OK;
}
