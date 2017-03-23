//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:40分:19秒  
// ><文件     ><  signal.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\callback  
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
// ><修改日期 ><  2017年:03月:21日   17时:40分:19秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Copyright (c) 2013 Hugh Bailey <obs.jim@gmail.com>
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

#pragma once

#include "../util/c99defs.h"

#include "calldata.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Signal handler
 *
 *   This is used to create a signal handler which can broadcast events
 * to one or more callbacks connected to a signal.
 */

struct signal_handler;
typedef struct signal_handler signal_handler_t;// xzm_@_信号句柄，涉及到堆栈
typedef void (*signal_callback_t)(void*, calldata_t*);// xzm_@_信号回调函数

EXPORT signal_handler_t *signal_handler_create(void);
EXPORT void signal_handler_destroy(signal_handler_t *handler);

EXPORT bool signal_handler_add(signal_handler_t *handler,
		const char *signal_decl);

static inline bool signal_handler_add_array(signal_handler_t *handler,
		const char **signal_decls)
{
	bool success = true;
	if (!signal_decls)
		return false;

	while (*signal_decls)
		if (!signal_handler_add(handler, *(signal_decls++)))
			success = false;

	return success;
}

EXPORT void signal_handler_connect(signal_handler_t *handler,
		const char *signal, signal_callback_t callback, void *data);
EXPORT void signal_handler_disconnect(signal_handler_t *handler,
		const char *signal, signal_callback_t callback, void *data);

EXPORT void signal_handler_signal(signal_handler_t *handler, const char *signal,
		calldata_t *params);

#ifdef __cplusplus
}
#endif
