//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:56分:35秒  
// ><文件     ><  dc-capture.h  
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
// ><修改日期 ><  2017年:03月:21日   16时:56分:35秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <obs-module.h>

#define NUM_TEXTURES 2

struct dc_capture {
	int          cur_tex;
	gs_texture_t *textures[NUM_TEXTURES];
	bool         textures_written[NUM_TEXTURES];
	int          x, y;
	uint32_t     width;
	uint32_t     height;
	int          num_textures;

	bool         compatibility;
	HDC          hdc;
	HBITMAP      bmp, old_bmp;
	BYTE         *bits;

	bool         capture_cursor;
	bool         cursor_captured;
	CURSORINFO   ci;

	bool         valid;
};

extern void dc_capture_init(struct dc_capture *capture, int x, int y,
		uint32_t width, uint32_t height, bool cursor,
		bool compatibility);
extern void dc_capture_free(struct dc_capture *capture);

extern void dc_capture_capture(struct dc_capture *capture, HWND window);
extern void dc_capture_render(struct dc_capture *capture, gs_effect_t *effect);
