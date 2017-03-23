//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:53分:49秒  
// ><文件     ><  obs-scene.h  
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
// ><修改日期 ><  2017年:03月:21日   17时:53分:49秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/******************************************************************************
    Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

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

#include "obs.h"
#include "obs-internal.h"
#include "graphics/matrix4.h"

/* how obs scene! */

struct item_action {
	bool visible;
	uint64_t timestamp;
};

struct obs_scene_item {
	volatile long         ref;
	volatile bool         removed;

	struct obs_scene      *parent;
	struct obs_source     *source;
	volatile long         active_refs;
	volatile long         defer_update;
	bool                  user_visible;
	bool                  visible;
	bool                  selected;

	gs_texrender_t        *item_render;
	struct obs_sceneitem_crop crop;

	struct vec2           pos;
	struct vec2           scale;
	float                 rot;
	uint32_t              align;

	/* last width/height of the source, this is used to check whether
	 * ths transform needs updating */
	uint32_t              last_width;
	uint32_t              last_height;

	struct vec2           output_scale;
	enum obs_scale_type   scale_filter;

	struct matrix4        box_transform;
	struct matrix4        draw_transform;

	enum obs_bounds_type  bounds_type;
	uint32_t              bounds_align;
	struct vec2           bounds;

	obs_hotkey_pair_id    toggle_visibility;

	pthread_mutex_t       actions_mutex;
	DARRAY(struct item_action) audio_actions;

	/* would do **prev_next, but not really great for reordering */
	struct obs_scene_item *prev;
	struct obs_scene_item *next;
};

struct obs_scene {
	struct obs_source     *source;

	pthread_mutex_t       video_mutex;
	pthread_mutex_t       audio_mutex;
	struct obs_scene_item *first_item;
};
