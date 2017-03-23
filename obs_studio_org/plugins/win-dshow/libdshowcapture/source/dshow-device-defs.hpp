//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:46��:27��  
// ><�ļ�     ><  dshow-device-defs.hpp  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:46��:27��  
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

namespace DShow {

#define COMMON_ENCODED_CX         720
#define COMMON_ENCODED_CY         480
#define COMMON_ENCODED_INTERVAL   (10010000000LL/60000LL)
#define COMMON_ENCODED_VFORMAT    VideoFormat::H264
#define COMMON_ENCODED_SAMPLERATE 48000

static const EncodedDevice HD_PVR1 = {
	COMMON_ENCODED_VFORMAT,
	0x1011UL,
	COMMON_ENCODED_CX,
	COMMON_ENCODED_CY,
	COMMON_ENCODED_INTERVAL,
	AudioFormat::AC3,
	0x1100UL,
	COMMON_ENCODED_SAMPLERATE
};

static const EncodedDevice HD_PVR2 = {
	COMMON_ENCODED_VFORMAT,
	0x1011UL,
	COMMON_ENCODED_CX,
	COMMON_ENCODED_CY,
	COMMON_ENCODED_INTERVAL,
	AudioFormat::AAC,
	0x1100UL,
	COMMON_ENCODED_SAMPLERATE
};

static const EncodedDevice Roxio = {
	COMMON_ENCODED_VFORMAT,
	0x1011UL,
	COMMON_ENCODED_CX,
	COMMON_ENCODED_CY,
	COMMON_ENCODED_INTERVAL,
	AudioFormat::AAC,
	0x010FUL,
	COMMON_ENCODED_SAMPLERATE,
};

static const EncodedDevice HD_PVR_Rocket = {
	COMMON_ENCODED_VFORMAT,
	0x07D1UL,
	COMMON_ENCODED_CX,
	COMMON_ENCODED_CY,
	COMMON_ENCODED_INTERVAL,
	AudioFormat::AAC,
	0x07D2UL,
	COMMON_ENCODED_SAMPLERATE
};

static const EncodedDevice AV_LGP = {
	COMMON_ENCODED_VFORMAT,
	68,
	COMMON_ENCODED_CX,
	COMMON_ENCODED_CY,
	COMMON_ENCODED_INTERVAL,
	AudioFormat::AAC,
	69,
	COMMON_ENCODED_SAMPLERATE
};

}; /* namespace DShow */
