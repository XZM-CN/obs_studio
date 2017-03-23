//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   17时:41分:08秒  
// ><文件     ><  bounds.h  
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
// ><修改日期 ><  2017年:03月:21日   17时:41分:08秒  
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

#include "math-defs.h"
#include "vec3.h"

/*
 * Axis Aligned Bounding Box
 */

#ifdef __cplusplus
extern "C" {
#endif

#define BOUNDS_MAX_X 1
#define BOUNDS_MAX_Y 2
#define BOUNDS_MAX_Z 4

#define BOUNDS_OUTSIDE 1
#define BOUNDS_INSIDE  2
#define BOUNDS_PARTIAL 3

struct bounds {
	struct vec3 min, max;
};

static inline void bounds_zero(struct bounds *dst)
{
	vec3_zero(&dst->min);
	vec3_zero(&dst->max);
}

static inline void bounds_copy(struct bounds *dst, const struct bounds *b)
{
	vec3_copy(&dst->min, &b->min);
	vec3_copy(&dst->max, &b->max);
}

EXPORT void bounds_move(struct bounds *dst, const struct bounds *b,
		const struct vec3 *v);

EXPORT void bounds_scale(struct bounds *dst, const struct bounds *b,
		const struct vec3 *v);

EXPORT void bounds_merge(struct bounds *dst, const struct bounds *b1,
		const struct bounds *b2);
EXPORT void bounds_merge_point(struct bounds *dst, const struct bounds *b,
		const struct vec3 *v);

EXPORT void bounds_get_point(struct vec3 *dst, const struct bounds *b,
		unsigned int i);
EXPORT void bounds_get_center(struct vec3 *dst, const struct bounds *b);

/**
 * Note: transforms as OBB, then converts back to AABB, which can result in
 * the actual size becoming larger than it originally was.
 */
EXPORT void bounds_transform(struct bounds *dst, const struct bounds *b,
		const struct matrix4 *m);
EXPORT void bounds_transform3x4(struct bounds *dst, const struct bounds *b,
		const struct matrix3 *m);

EXPORT bool bounds_intersection_ray(const struct bounds *b,
		const struct vec3 *orig, const struct vec3 *dir, float *t);
EXPORT bool bounds_intersection_line(const struct bounds *b,
		const struct vec3 *p1, const struct vec3 *p2, float *t);

EXPORT bool bounds_plane_test(const struct bounds *b, const struct plane *p);
EXPORT bool bounds_under_plane(const struct bounds *b,
		const struct plane *p);

static inline bool bounds_inside(const struct bounds *b,
		const struct bounds *test)
{
	return test->min.x >= b->min.x &&
	       test->min.y >= b->min.y &&
	       test->min.z >= b->min.z &&
	       test->max.x <= b->max.x &&
	       test->max.y <= b->max.y &&
	       test->max.z <= b->max.z;
}

static inline bool bounds_vec3_inside(const struct bounds *b,
		const struct vec3 *v)
{
	return  v->x >= (b->min.x-EPSILON) &&
		v->x <= (b->max.x+EPSILON) &&
		v->y >= (b->min.y-EPSILON) &&
		v->y <= (b->max.y+EPSILON) &&
		v->z >= (b->min.z-EPSILON) &&
		v->z <= (b->max.z+EPSILON);
}

EXPORT bool bounds_intersects(const struct bounds *b,
		const struct bounds *test, float epsilon);
EXPORT bool bounds_intersects_obb(const struct bounds *b,
		const struct bounds *test, const struct matrix4 *m,
		float epsilon);
EXPORT bool bounds_intersects_obb3x4(const struct bounds *b,
		const struct bounds *test, const struct matrix3 *m,
		float epsilon);

static inline bool bounds_intersects_ray(const struct bounds *b,
		const struct vec3 *orig, const struct vec3 *dir)
{
	float t;
	return bounds_intersection_ray(b, orig, dir, &t);
}

static inline bool bounds_intersects_line(const struct bounds *b,
		const struct vec3 *p1, const struct vec3 *p2)
{
	float t;
	return bounds_intersection_line(b, p1, p2, &t);
}

EXPORT float bounds_min_dist(const struct bounds *b, const struct plane *p);

#ifdef __cplusplus
}
#endif
