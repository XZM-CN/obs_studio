//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:05分:45秒  
// ><文件     ><  ff-timer.c  
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
// ><修改日期 ><  2017年:03月:21日   18时:05分:45秒  
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

#include "ff-timer.h"

#include <libavutil/time.h>
#include <time.h>
#include <string.h>
#include <assert.h>

static void *timer_thread(void *opaque)
{
	struct ff_timer *timer = (struct ff_timer *)opaque;
	int ret;

	while (true) {
		bool callback = false;
		pthread_mutex_lock(&timer->mutex);

		if (timer->abort) {
			pthread_mutex_unlock(&timer->mutex);
			break;
		}

		uint64_t current_time = av_gettime();
		if (current_time < timer->next_wake) {
			struct timespec sleep_time = {
				.tv_sec = timer->next_wake / AV_TIME_BASE,
				.tv_nsec = (timer->next_wake % AV_TIME_BASE)
						* 1000
			};

			ret = pthread_cond_timedwait(&timer->cond,
					&timer->mutex, &sleep_time);
			if (ret != ETIMEDOUT) {
				// failed to wait, just sleep
				av_usleep((unsigned)(timer->next_wake
						- current_time));
			}

			pthread_mutex_unlock(&timer->mutex);
			continue;

			// we can be woken up merely to set a sooner wake time

		} else {
			// no new next_wake, sleep until we get something
			av_usleep(1000);
		}

		// we woke up for some reason
		current_time = av_gettime();
		if (timer->next_wake <= current_time || timer->needs_wake) {
			callback = true;
			timer->needs_wake = false;
		}

		pthread_mutex_unlock(&timer->mutex);

		if (callback)
			timer->callback(timer->opaque);
	}

	return NULL;
}

bool ff_timer_init(struct ff_timer *timer, ff_timer_callback callback,
		void *opaque)
{
	memset(timer, 0, sizeof(struct ff_timer));
	timer->abort = false;
	timer->callback = callback;
	timer->opaque = opaque;

	if (pthread_mutexattr_init(&timer->mutexattr) != 0)
		goto fail;
	if (pthread_mutexattr_settype(&timer->mutexattr,
			PTHREAD_MUTEX_RECURSIVE))
		goto fail1;
	if (pthread_mutex_init(&timer->mutex, &timer->mutexattr) != 0)
		goto fail1;
	if (pthread_cond_init(&timer->cond, NULL) != 0)
		goto fail2;

	if (pthread_create(&timer->timer_thread, NULL, timer_thread, timer) != 0)
		goto fail3;

	return true;

fail3:
	pthread_cond_destroy(&timer->cond);
fail2:
	pthread_mutex_destroy(&timer->mutex);
fail1:
	pthread_mutexattr_destroy(&timer->mutexattr);
fail:
	return false;
}

void ff_timer_free(struct ff_timer *timer)
{
	void *thread_result;

	assert(timer != NULL);

	pthread_mutex_lock(&timer->mutex);
	timer->abort = true;
	pthread_cond_signal(&timer->cond);
	pthread_mutex_unlock(&timer->mutex);

	pthread_join(timer->timer_thread, &thread_result);

	pthread_mutex_destroy(&timer->mutex);
	pthread_mutexattr_destroy(&timer->mutexattr);
	pthread_cond_destroy(&timer->cond);
}

void ff_timer_schedule(struct ff_timer *timer, uint64_t microseconds)
{
	uint64_t cur_time = av_gettime();
	uint64_t new_wake_time = cur_time + microseconds;

	pthread_mutex_lock(&timer->mutex);

	timer->needs_wake = true;
	if (new_wake_time < timer->next_wake || cur_time > timer->next_wake)
		timer->next_wake = new_wake_time;

	pthread_cond_signal(&timer->cond);

	pthread_mutex_unlock(&timer->mutex);
}
