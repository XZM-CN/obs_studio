//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:42分:19秒  
// ><文件     ><  http.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\obs-outputs\librtmp  
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
// ><修改日期 ><  2017年:03月:21日   16时:42分:19秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __RTMP_HTTP_H__
#define __RTMP_HTTP_H__
/*
 *      Copyright (C) 2010 Howard Chu
 *      Copyright (C) 2010 Antti Ajanki
 *
 *  This file is part of librtmp.
 *
 *  librtmp is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation; either version 2.1,
 *  or (at your option) any later version.
 *
 *  librtmp is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with librtmp see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 *  http://www.gnu.org/copyleft/lgpl.html
 */

typedef enum
{
    HTTPRES_OK,               /* result OK */
    HTTPRES_OK_NOT_MODIFIED,  /* not modified since last request */
    HTTPRES_NOT_FOUND,        /* not found */
    HTTPRES_BAD_REQUEST,      /* client error */
    HTTPRES_SERVER_ERROR,     /* server reported an error */
    HTTPRES_REDIRECTED,       /* resource has been moved */
    HTTPRES_LOST_CONNECTION   /* connection lost while waiting for data */
} HTTPResult;

struct HTTP_ctx
{
    char *date;
    int size;
    int status;
    void *data;
};

typedef size_t (HTTP_read_callback)(void *ptr, size_t size, size_t nmemb, void *stream);

HTTPResult HTTP_get(struct HTTP_ctx *http, const char *url, HTTP_read_callback *cb);

#endif
