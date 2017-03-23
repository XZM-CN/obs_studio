//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:46��:08��  
// ><�ļ�     ><  dshow-base.hpp  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\win-dshow\libdshowcapture\source  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:46��:08��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *  Copyright (C) 2014 Hugh Bailey <obs.jim@gmail.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 */

#pragma once

#define WIN32_MEAN_AND_LEAN
#define __STREAMS__
#include <windows.h>
#include <dshow.h>
#include <ks.h>
#include <ksmedia.h>
#include <ksproxy.h>
#include <Amaudio.h>
#include <Dvdmedia.h>

#include "ComPtr.hpp"
#include "CoTaskMemPtr.hpp"

#include <string>
using namespace std;

#define DSHOW_UNUSED(param) (void)param;

namespace DShow {

bool CreateFilterGraph(IGraphBuilder **graph, ICaptureGraphBuilder2 **builder,
		IMediaControl **control);

void LogFilters(IGraphBuilder *graph);

bool GetDeviceFilter(const IID &type, const wchar_t *name, const wchar_t *path,
		IBaseFilter **filter);

bool GetFilterPin(IBaseFilter *filter, const GUID &type, const GUID &category,
		PIN_DIRECTION dir, IPin **pin);

bool GetPinByName(IBaseFilter *filter, PIN_DIRECTION dir, const wchar_t *name,
		IPin **pin);

bool GetPinByMedium(IBaseFilter *filter, REGPINMEDIUM &medium, IPin **pin);
bool GetFilterByMedium(const CLSID &id, REGPINMEDIUM &medium,
		IBaseFilter **filter);

bool GetPinMedium(IPin *pin, REGPINMEDIUM &medium);

bool DirectConnectFilters(IFilterGraph *graph, IBaseFilter *filterOut,
		IBaseFilter *filterIn);

/**
 * This maps a created demuxer pin to a packet ID for the mux stream.  Note
 * that this needs to be called after the device filters are connected to the
 * demux filter.
 */
HRESULT MapPinToPacketID(IPin *pin, ULONG packetID);

wstring ConvertHRToEnglish(HRESULT hr);

}; /* namespace DShow */
