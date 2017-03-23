//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:46分:01秒  
// ><文件     ><  device.hpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:46分:01秒  
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
#include "capture-filter.hpp"

#include <string>
#include <vector>
using namespace std;

namespace DShow {

struct EncodedData {
	long long                      lastStartTime = 0;
	long long                      lastStopTime  = 0;
	vector<unsigned char>          bytes;
};

struct EncodedDevice {
	VideoFormat videoFormat;
	ULONG       videoPacketID;
	long        width;
	long        height;
	long long   frameInterval;

	AudioFormat audioFormat;
	ULONG       audioPacketID;
	DWORD       samplesPerSec;
};

struct HDevice {
	ComPtr<IGraphBuilder>          graph;
	ComPtr<ICaptureGraphBuilder2>  builder;
	ComPtr<IMediaControl>          control;

	ComPtr<IBaseFilter>            videoFilter;
	ComPtr<IBaseFilter>            audioFilter;
	ComPtr<CaptureFilter>          videoCapture;
	ComPtr<CaptureFilter>          audioCapture;
	ComPtr<IBaseFilter>            audioOutput;
	ComPtr<IBaseFilter>            rocketEncoder;
	MediaType                      videoMediaType;
	MediaType                      audioMediaType;
	VideoConfig                    videoConfig;
	AudioConfig                    audioConfig;

	bool                           encodedDevice = false;
	bool                           initialized;
	bool                           active;

	EncodedData                    encodedVideo;
	EncodedData                    encodedAudio;

	HDevice();
	~HDevice();

	void ConvertVideoSettings();
	void ConvertAudioSettings();

	bool EnsureInitialized(const wchar_t *func);
	bool EnsureActive(const wchar_t *func);
	bool EnsureInactive(const wchar_t *func);

	inline void SendToCallback(bool video,
			unsigned char *data, size_t size,
			long long startTime, long long stopTime);

	void Receive(bool video, IMediaSample *sample);

	bool SetupEncodedVideoCapture(IBaseFilter *filter,
				VideoConfig &config,
				const EncodedDevice &info);

	bool SetupExceptionVideoCapture(IBaseFilter *filter,
			VideoConfig &config);

	bool SetupExceptionAudioCapture(IPin *pin);

	bool SetupVideoCapture(IBaseFilter *filter, VideoConfig &config);
	bool SetupAudioCapture(IBaseFilter *filter, AudioConfig &config);

	bool SetupAudioOutput(IBaseFilter *filter, AudioConfig &config);

	bool SetVideoConfig(VideoConfig *config);
	bool SetAudioConfig(AudioConfig *config);

	bool CreateGraph();
	bool FindCrossbar(IBaseFilter *filter, IBaseFilter **crossbar);
	bool ConnectPins(const GUID &category, const GUID &type,
			IBaseFilter *filter, IBaseFilter *capture);
	bool RenderFilters(const GUID &category, const GUID &type,
			IBaseFilter *filter, IBaseFilter *capture);
	void SetAudioBuffering(int bufferingMs);
	bool ConnectFilters();
	void DisconnectFilters();
	Result Start();
	void Stop();
};

}; /* namespace DShow */
