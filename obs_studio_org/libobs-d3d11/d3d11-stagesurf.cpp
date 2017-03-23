//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:07分:20秒  
// ><文件     ><  d3d11-stagesurf.cpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs-d3d11  
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
// ><修改日期 ><  2017年:03月:21日   18时:07分:20秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "d3d11-subsystem.hpp"

gs_stage_surface::gs_stage_surface(gs_device_t *device, uint32_t width,
		uint32_t height, gs_color_format colorFormat)
	: gs_obj     (device, gs_type::gs_stage_surface),
	  width      (width),
	  height     (height),
	  format     (colorFormat),
	  dxgiFormat (ConvertGSTextureFormat(colorFormat))
{
	HRESULT hr;

	memset(&td, 0, sizeof(td));
	td.Width            = width;
	td.Height           = height;
	td.MipLevels        = 1;
	td.ArraySize        = 1;
	td.Format           = dxgiFormat;
	td.SampleDesc.Count = 1;
	td.CPUAccessFlags   = D3D11_CPU_ACCESS_READ;
	td.Usage            = D3D11_USAGE_STAGING;

	hr = device->device->CreateTexture2D(&td, NULL, texture.Assign());
	if (FAILED(hr))
		throw HRError("Failed to create staging surface", hr);
}
