//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:47分:11秒  
// ><文件     ><  encoder.hpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\win-dshow\libdshowcapture\source  
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
// ><修改日期 ><  2017年:03月:21日   16时:47分:11秒  
// ><原因     ><    
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

#include "../dshowcapture.hpp"
#include "output-filter.hpp"
#include "capture-filter.hpp"

#include <string>
#include <vector>
#include <deque>
#include <mutex>
using namespace std;

struct EncodedData {
	vector<unsigned char>          data;

	inline EncodedData() {}

	inline EncodedData(unsigned char *data_, size_t size)
	{
		data.resize(size);
		memcpy(data.data(), data_, size);
	}
};

namespace DShow {

struct HVideoEncoder {
	ComPtr<IGraphBuilder>          graph;
	ComPtr<ICaptureGraphBuilder2>  builder;
	ComPtr<IMediaControl>          control;

	ComPtr<IBaseFilter>            encoder;
	ComPtr<IBaseFilter>            device;
	ComPtr<OutputFilter>           output;
	ComPtr<CaptureFilter>          capture;

	VideoEncoderConfig             config;

	mutex                          packetMutex;
	deque<EncodedData>             packets;
	EncodedData                    curPacket;

	deque<long long>               ptsVals;

	bool                           initialized = false;
	bool                           active = false;

	HVideoEncoder();
	~HVideoEncoder();

	bool SetupCrossbar();

	void Receive(IMediaSample *s);

	bool ConnectFilters();

	void InitializeVideoFormat(MediaType &mt);
	bool SetupEncoder(IBaseFilter *filter);

	bool SetConfig(VideoEncoderConfig &config);

	bool Encode(unsigned char *frame[DSHOW_MAX_PLANES],
			size_t linesize[DSHOW_MAX_PLANES],
			long long timestampStart, long long timestampEnd,
			EncoderPacket &packet, bool &new_packet);
};

};
