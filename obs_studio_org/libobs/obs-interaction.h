//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:53分:13秒  
// ><文件     ><  obs-interaction.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs  
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
// ><修改日期 ><  2017年:03月:21日   17时:53分:13秒  
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

#include "util/c99defs.h"

enum obs_interaction_flags {
	INTERACT_NONE          = 0,
	INTERACT_CAPS_KEY      = 1,
	INTERACT_SHIFT_KEY     = 1 << 1,
	INTERACT_CONTROL_KEY   = 1 << 2,
	INTERACT_ALT_KEY       = 1 << 3,
	INTERACT_MOUSE_LEFT    = 1 << 4,
	INTERACT_MOUSE_MIDDLE  = 1 << 5,
	INTERACT_MOUSE_RIGHT   = 1 << 6,
	INTERACT_COMMAND_KEY   = 1 << 7,
	INTERACT_NUMLOCK_KEY   = 1 << 8,
	INTERACT_IS_KEY_PAD    = 1 << 9,
	INTERACT_IS_LEFT       = 1 << 10,
	INTERACT_IS_RIGHT      = 1 << 11
};

enum obs_mouse_button_type {
	MOUSE_LEFT,
	MOUSE_MIDDLE,
	MOUSE_RIGHT
};

struct obs_mouse_event {
	uint32_t            modifiers;
	int32_t             x;
	int32_t             y;
};

struct obs_key_event {
	uint32_t            modifiers;
	char                *text;
	uint32_t            native_modifiers;
	uint32_t            native_scancode;
	uint32_t            native_vkey;
};
