//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   17ʱ:57��:54��  
// ><�ļ�     ><  frame-rate.h  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\media-io  
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
// ><�޸����� ><  2017��:03��:21��   17ʱ:57��:54��  
// ><ԭ��     ><    
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
