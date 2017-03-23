//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:56分:45秒  
// ><文件     ><  hook-helpers.h  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\win-capture  
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
// ><修改日期 ><  2017年:03月:21日   16时:56分:45秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#if !defined(__cplusplus) && !defined(inline)
#define inline __inline
#endif

#define GC_EVENT_FLAGS (EVENT_MODIFY_STATE | SYNCHRONIZE)
#define GC_MUTEX_FLAGS (SYNCHRONIZE)

static inline HANDLE create_event(const wchar_t *name)
{
	return CreateEventW(NULL, false, false, name);
}

static inline HANDLE open_event(const wchar_t *name)
{
	return OpenEventW(GC_EVENT_FLAGS, false, name);
}

static inline HANDLE create_mutex(const wchar_t *name)
{
	return CreateMutexW(NULL, false, name);
}

static inline HANDLE open_mutex(const wchar_t *name)
{
	return OpenMutexW(GC_MUTEX_FLAGS, false, name);
}

static inline HANDLE create_event_plus_id(const wchar_t *name, DWORD id)
{
	wchar_t new_name[64];
	_snwprintf(new_name, 64, L"%s%lu", name, id);
	return create_event(new_name);
}

static inline HANDLE create_mutex_plus_id(const wchar_t *name, DWORD id)
{
	wchar_t new_name[64];
	_snwprintf(new_name, 64, L"%s%lu", name, id);
	return create_mutex(new_name);
}

static inline bool object_signalled(HANDLE event)
{
	if (!event)
		return false;

	return WaitForSingleObject(event, 0) == WAIT_OBJECT_0;
}

