//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:40分:03秒  
// ><文件     ><  decl.h  
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
// ><修改日期 ><  2017年:03月:21日   17时:40分:03秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Copyright (c) 2014 Hugh Bailey <obs.jim@gmail.com>
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

#include "calldata.h"
#include "../util/darray.h"

#ifdef __cplusplus
extern "C" {
#endif

struct decl_param {
	char                 *name;
	enum call_param_type type;
	uint32_t             flags;
};

static inline void decl_param_free(struct decl_param *param)
{
	if (param->name)
		bfree(param->name);
	memset(param, 0, sizeof(struct decl_param));
}

// 数据类型参数信息
struct decl_info {
	char                      *name;
	const char                *decl_string;
	DARRAY(struct decl_param) params;
};

static inline void decl_info_free(struct decl_info *decl)
{
	if (decl) {
		for (size_t i = 0; i < decl->params.num; i++)
			decl_param_free(decl->params.array+i);
		da_free(decl->params);

		bfree(decl->name);
		memset(decl, 0, sizeof(struct decl_info));
	}
}

EXPORT bool parse_decl_string(struct decl_info *decl, const char *decl_string);

#ifdef __cplusplus
}
#endif
