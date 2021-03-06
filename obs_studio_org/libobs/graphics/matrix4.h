//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:42分:47秒  
// ><文件     ><  matrix4.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\libobs\graphics  
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
// ><修改日期 ><  2017年:03月:21日   17时:42分:47秒  
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

#include "vec3.h"
#include "vec4.h"
#include "axisang.h"

/* 4x4 Matrix */

#ifdef __cplusplus
extern "C" {
#endif

struct matrix3;

struct matrix4 {
	struct vec4 x, y, z, t;
};

static inline void matrix4_copy(struct matrix4 *dst, const struct matrix4 *m)
{
	dst->x.m = m->x.m;
	dst->y.m = m->y.m;
	dst->z.m = m->z.m;
	dst->t.m = m->t.m;
}

static inline void matrix4_identity(struct matrix4 *dst)
{
	vec4_zero(&dst->x);
	vec4_zero(&dst->y);
	vec4_zero(&dst->z);
	vec4_zero(&dst->t);
	dst->x.x = 1.0f;
	dst->y.y = 1.0f;
	dst->z.z = 1.0f;
	dst->t.w = 1.0f;
}

EXPORT void matrix4_from_matrix3(struct matrix4 *dst, const struct matrix3 *m);
EXPORT void matrix4_from_quat(struct matrix4 *dst, const struct quat *q);
EXPORT void matrix4_from_axisang(struct matrix4 *dst,
		const struct axisang *aa);

EXPORT void matrix4_mul(struct matrix4 *dst, const struct matrix4 *m1,
		const struct matrix4 *m2);

EXPORT float matrix4_determinant(const struct matrix4 *m);

EXPORT void matrix4_translate3v(struct matrix4 *dst, const struct matrix4 *m,
		const struct vec3 *v);
EXPORT void matrix4_translate4v(struct matrix4 *dst, const struct matrix4 *m,
		const struct vec4 *v);
EXPORT void matrix4_rotate(struct matrix4 *dst, const struct matrix4 *m,
		const struct quat *q);
EXPORT void matrix4_rotate_aa(struct matrix4 *dst, const struct matrix4 *m,
		const struct axisang *aa);
EXPORT void matrix4_scale(struct matrix4 *dst, const struct matrix4 *m,
		const struct vec3 *v);
EXPORT bool matrix4_inv(struct matrix4 *dst, const struct matrix4 *m);
EXPORT void matrix4_transpose(struct matrix4 *dst, const struct matrix4 *m);

EXPORT void matrix4_translate3v_i(struct matrix4 *dst, const struct vec3 *v,
		const struct matrix4 *m);
EXPORT void matrix4_translate4v_i(struct matrix4 *dst, const struct vec4 *v,
		const struct matrix4 *m);
EXPORT void matrix4_rotate_i(struct matrix4 *dst, const struct quat *q,
		const struct matrix4 *m);
EXPORT void matrix4_rotate_aa_i(struct matrix4 *dst, const struct axisang *aa,
		const struct matrix4 *m);
EXPORT void matrix4_scale_i(struct matrix4 *dst, const struct vec3 *v,
		const struct matrix4 *m);

static inline void matrix4_translate3f(struct matrix4 *dst,
		const struct matrix4 *m, float x, float y, float z)
{
	struct vec3 v;
	vec3_set(&v, x, y, z);
	matrix4_translate3v(dst, m, &v);
}

static inline void matrix4_rotate_aa4f(struct matrix4 *dst,
		const struct matrix4 *m, float x, float y, float z, float rot)
{
	struct axisang aa;
	axisang_set(&aa, x, y, z, rot);
	matrix4_rotate_aa(dst, m, &aa);
}

static inline void matrix4_scale3f(struct matrix4 *dst,
		const struct matrix4 *m, float x, float y, float z)
{
	struct vec3 v;
	vec3_set(&v, x, y, z);
	matrix4_scale(dst, m, &v);
}

#ifdef __cplusplus
}
#endif
