//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   18时:01分:12秒  
// ><文件     ><  profiler.hpp  
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
// ><修改日期 ><  2017年:03月:21日   18时:01分:12秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "profiler.h"

struct ScopeProfiler {
	const char *name;
	bool enabled = true;

	ScopeProfiler(const char *name)
		: name(name)
	{
		profile_start(name);
	}

	~ScopeProfiler() { Stop(); }

	ScopeProfiler(const ScopeProfiler &) = delete;
	ScopeProfiler(ScopeProfiler &&other)
		: name(other.name),
		  enabled(other.enabled)
	{
		other.enabled = false;
	}

	ScopeProfiler &operator=(const ScopeProfiler &) = delete;
	ScopeProfiler &operator=(ScopeProfiler &&other) = delete;

	void Stop()
	{
		if (!enabled)
			return;

		profile_end(name);
		enabled = false;
	}
};

#ifndef NO_PROFILER_MACROS

#define ScopeProfiler_NameConcatImpl(x, y) x ## y
#define ScopeProfiler_NameConcat(x, y) ScopeProfiler_NameConcatImpl(x, y)

#ifdef __COUNTER__
#define ScopeProfiler_Name(x) ScopeProfiler_NameConcat(x, __COUNTER__)
#else
#define ScopeProfiler_Name(x) ScopeProfiler_NameConcat(x, __LINE__)
#endif

#define ProfileScope(x) ScopeProfiler \
	ScopeProfiler_Name(SCOPE_PROFILE){x}

#endif
