//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:04分:00秒  
// ><文件     ><  ff-circular-queue.h  
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
// ><修改日期 ><  2017年:03月:21日   18时:04分:00秒  
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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <libavutil/mem.h>
#include <stdbool.h>

struct ff_circular_queue {
	pthread_mutex_t mutex;
	pthread_cond_t cond;

	void **slots;

	int item_size;
	int capacity;
	int size;

	int write_index;
	int read_index;

	bool abort;
};

typedef struct ff_circular_queue ff_circular_queue_t;

bool ff_circular_queue_init(struct ff_circular_queue *cq, int item_size,
		int capacity);
void ff_circular_queue_abort(struct ff_circular_queue *cq);
void ff_circular_queue_free(struct ff_circular_queue *cq);

void ff_circular_queue_wait_write(struct ff_circular_queue *cq);
void *ff_circular_queue_peek_write(struct ff_circular_queue *cq);
void ff_circular_queue_advance_write(struct ff_circular_queue *cq, void *item);
void *ff_circular_queue_peek_read(struct ff_circular_queue *cq);
void ff_circular_queue_advance_read(struct ff_circular_queue *cq);

#ifdef __cplusplus
}
#endif
