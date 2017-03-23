//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:40分:40秒  
// ><文件     ><  obs-filters.c  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\obs-filters  
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
// ><修改日期 ><  2017年:03月:21日   16时:40分:40秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <obs-module.h>
#include "obs-filters-config.h"

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE("obs-filters", "en-US")

extern struct obs_source_info mask_filter;
extern struct obs_source_info crop_filter;
extern struct obs_source_info gain_filter;
extern struct obs_source_info color_filter;
extern struct obs_source_info scale_filter;
extern struct obs_source_info scroll_filter;
extern struct obs_source_info color_key_filter;
extern struct obs_source_info color_grade_filter;
extern struct obs_source_info sharpness_filter;
extern struct obs_source_info chroma_key_filter;
extern struct obs_source_info async_delay_filter;
#if SPEEXDSP_ENABLED
extern struct obs_source_info noise_suppress_filter;
#endif
extern struct obs_source_info noise_gate_filter;
extern struct obs_source_info compressor_filter;

bool obs_module_load(void)
{
	obs_register_source(&mask_filter);
	obs_register_source(&crop_filter);
	obs_register_source(&gain_filter);
	obs_register_source(&color_filter);
	obs_register_source(&scale_filter);
	obs_register_source(&scroll_filter);
	obs_register_source(&color_key_filter);
	obs_register_source(&color_grade_filter);
	obs_register_source(&sharpness_filter);
	obs_register_source(&chroma_key_filter);
	obs_register_source(&async_delay_filter);
#if SPEEXDSP_ENABLED
	obs_register_source(&noise_suppress_filter);
#endif
	obs_register_source(&noise_gate_filter);
	obs_register_source(&compressor_filter);
	return true;
}
