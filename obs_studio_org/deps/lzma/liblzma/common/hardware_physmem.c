//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   18ʱ:14��:57��  
// ><�ļ�     ><  hardware_physmem.c  
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
// ><�޸����� ><  2017��:03��:21��   18ʱ:14��:57��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
/// \file       hardware_physmem.c
/// \brief      Get the total amount of physical memory (RAM)
//
//  Author:     Jonathan Nieder
//
//  This file has been put into the public domain.
//  You can do whatever you want with this file.
//
///////////////////////////////////////////////////////////////////////////////

#include "common.h"

#include "tuklib_physmem.h"


extern LZMA_API(uint64_t)
lzma_physmem(void)
{
	// It is simpler to make lzma_physmem() a wrapper for
	// tuklib_physmem() than to hack appropriate symbol visiblity
	// support for the tuklib modules.
	return tuklib_physmem();
}
