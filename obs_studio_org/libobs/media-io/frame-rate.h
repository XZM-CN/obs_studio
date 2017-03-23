//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:57分:54秒  
// ><文件     ><  frame-rate.h  
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
// ><修改日期 ><  2017年:03月:21日   17时:57分:54秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct media_frames_per_second {
	uint32_t numerator;
	uint32_t denominator;
};

static inline double media_frames_per_second_to_frame_interval(
		struct media_frames_per_second fps)
{
	return (double)fps.denominator / fps.numerator;
}

static inline double media_frames_per_second_to_fps(
		struct media_frames_per_second fps)
{
	return (double)fps.numerator / fps.denominator;
}

static inline bool media_frames_per_second_is_valid(
		struct media_frames_per_second fps)
{
	return fps.numerator && fps.denominator;
}

#ifdef __cplusplus
}
#endif
