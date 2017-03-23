//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:05分:05秒  
// ><文件     ><  ff-callbacks.c  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\deps\libff\libff  
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
// ><修改日期 ><  2017年:03月:21日   18时:05分:05秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Copyright (c) 2015 John R. Bradley <jrb@turrettech.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "ff-callbacks.h"

bool ff_callbacks_frame(struct ff_callbacks *callbacks,
		struct ff_frame *frame)
{
	if (callbacks->frame == NULL)
		return true;

	return callbacks->frame(frame, callbacks->opaque);
}

bool ff_callbacks_format(struct ff_callbacks *callbacks,
		AVCodecContext *codec_context)
{
	if (callbacks->format == NULL)
		return true;

	return callbacks->format(codec_context, callbacks->opaque);
}

bool ff_callbacks_initialize(struct ff_callbacks *callbacks)
{
	if (callbacks->initialize == NULL)
		return true;

	return callbacks->initialize(callbacks->opaque);
}

bool ff_callbacks_frame_initialize(struct ff_frame *frame,
		struct ff_callbacks *callbacks)
{
	if (callbacks->frame_initialize == NULL)
		return true;

	return callbacks->frame_initialize(frame, callbacks->opaque);
}

bool ff_callbacks_frame_free(struct ff_frame *frame,
		struct ff_callbacks *callbacks)
{
	if (callbacks->frame_free == NULL)
		return true;

	return callbacks->frame_free(frame, callbacks->opaque);
}
