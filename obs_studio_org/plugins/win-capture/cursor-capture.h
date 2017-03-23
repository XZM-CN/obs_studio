//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:56分:29秒  
// ><文件     ><  cursor-capture.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\win-capture  
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
// ><修改日期 ><  2017年:03月:21日   16时:56分:29秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdint.h>

struct cached_cursor {
	gs_texture_t *texture;
	uint32_t cx;
	uint32_t cy;
};

struct cursor_data {
	gs_texture_t                   *texture;
	HCURSOR                        current_cursor;
	POINT                          cursor_pos;
	long                           x_hotspot;
	long                           y_hotspot;
	bool                           visible;

	uint32_t                       last_cx;
	uint32_t                       last_cy;

	DARRAY(struct cached_cursor)   cached_textures;
};

extern void cursor_capture(struct cursor_data *data);
extern void cursor_draw(struct cursor_data *data, long x_offset, long y_offset,
		float x_scale, float y_scale, long width, long height);
extern void cursor_data_free(struct cursor_data *data);
