//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:58分:25秒  
// ><文件     ><  video-scaler.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\media-io  
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
// ><修改日期 ><  2017年:03月:21日   17时:58分:25秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2014 by Hugh Bailey <obs.jim@gmail.com>

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

#pragma once

#include "../util/c99defs.h"
#include "video-io.h"

#ifdef __cplusplus
extern "C" {
#endif

struct video_scaler;
typedef struct video_scaler video_scaler_t;

#define VIDEO_SCALER_SUCCESS         0
#define VIDEO_SCALER_BAD_CONVERSION -1
#define VIDEO_SCALER_FAILED         -2

EXPORT int video_scaler_create(video_scaler_t **scaler,
		const struct video_scale_info *dst,
		const struct video_scale_info *src,
		enum video_scale_type type);
EXPORT void video_scaler_destroy(video_scaler_t *scaler);

EXPORT bool video_scaler_scale(video_scaler_t *scaler,
		uint8_t *output[], const uint32_t out_linesize[],
		const uint8_t *const input[], const uint32_t in_linesize[]);

#ifdef __cplusplus
}
#endif
