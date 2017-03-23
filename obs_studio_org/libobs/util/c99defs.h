//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:59分:56秒  
// ><文件     ><  c99defs.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\util  
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
// ><修改日期 ><  2017年:03月:21日   17时:59分:56秒  
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

/*
 * Contains hacks for getting some C99 stuff working in VC, things like
 * bool, inline, stdint
 */

#define UNUSED_PARAMETER(param) (void)param

#ifdef _MSC_VER
#define DEPRECATED __declspec(deprecated)
#define FORCE_INLINE __forceinline
#else
#define DEPRECATED __attribute__ ((deprecated))
#define FORCE_INLINE inline __attribute__((always_inline))
#endif

#ifdef _MSC_VER

/* Microsoft is one of the most inept companies on the face of the planet.
 * The fact that even visual studio 2013 doesn't support the standard 'inline'
 * keyword is so incredibly stupid that I just can't imagine what sort of
 * incredibly inept moron could possibly be managing the visual C compiler
 * project.  They should be fired, and legally forbidden to have a job in
 * ANYTHING even REMOTELY related to programming.  FOREVER.  This should also
 * apply to the next 10 generations all of their descendents. */
#ifndef __cplusplus
#define inline __inline
#endif

#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

#if _MSC_VER && _MSC_VER < 0x0708

#include "vc/vc_stdint.h"
#include "vc/vc_stdbool.h"

#ifndef __off_t_defined
#define __off_t_defined
#if _FILE_OFFSET_BITS == 64
typedef long long off_t;
#else
typedef long off_t;
#endif
typedef int64_t off64_t;
#endif /* __off_t_defined */

#define SIZE_T_FORMAT "%u"

#else

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#define SIZE_T_FORMAT "%zu"

#endif /* _MSC_VER */
