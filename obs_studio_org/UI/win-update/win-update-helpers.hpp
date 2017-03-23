//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:31分:32秒  
// ><文件     ><  win-update-helpers.hpp  
// ><文件路径 ><  D:\newSvnCode\OBS\trunk\obs_studio\UI\win-update  
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
// ><修改日期 ><  2017年:03月:21日   16时:31分:32秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Wincrypt.h>

#include <jansson.h>

#include <cstdint>
#include <string>

/* ------------------------------------------------------------------------ */

template<typename T, void freefunc(T)> class CustomHandle {
	T handle;

public:
	inline CustomHandle() : handle(0) {}
	inline CustomHandle(T in) : handle(in) {}
	inline ~CustomHandle()
	{
		if (handle)
			freefunc(handle);
	}

	inline T *operator&() {return &handle;}
	inline operator T() const {return handle;}
	inline T get() const {return handle;}

	inline CustomHandle<T, freefunc> &operator=(T in)
	{
		if (handle)
			freefunc(handle);
		handle = in;
		return *this;
	}

	inline bool operator!() const {return !handle;}
};

void FreeProvider(HCRYPTPROV prov);
void FreeHash(HCRYPTHASH hash);
void FreeKey(HCRYPTKEY key);

using CryptProvider = CustomHandle<HCRYPTPROV, FreeProvider>;
using CryptHash     = CustomHandle<HCRYPTHASH, FreeHash>;
using CryptKey      = CustomHandle<HCRYPTKEY,  FreeKey>;

/* ------------------------------------------------------------------------ */

template<typename T> class LocalPtr {
	T *ptr = nullptr;

public:
	inline ~LocalPtr()
	{
		if (ptr)
			LocalFree(ptr);
	}

	inline T **operator&() {return &ptr;}
	inline operator T() const {return ptr;}
	inline T *get() const {return ptr;}

	inline bool operator!() const {return !ptr;}

	inline T *operator->() {return ptr;}
};

/* ------------------------------------------------------------------------ */

class Json {
	json_t *json;

public:
	inline Json() : json(nullptr) {}
	explicit inline Json(json_t *json_) : json(json_) {}
	inline Json(const Json &from) : json(json_incref(from.json)) {}
	inline Json(Json &&from) : json(from.json) {from.json = nullptr;}

	inline ~Json() {
		if (json)
			json_decref(json);
	}

	inline Json &operator=(json_t *json_)
	{
		if (json)
			json_decref(json);
		json = json_;
		return *this;
	}
	inline Json &operator=(const Json &from)
	{
		if (json)
			json_decref(json);
		json = json_incref(from.json);
		return *this;
	}
	inline Json &operator=(Json &&from)
	{
		if (json)
			json_decref(json);
		json = from.json;
		from.json = nullptr;
		return *this;
	}

	inline operator json_t *() const {return json;}

	inline bool operator!() const {return !json;}

	inline const char *GetString(const char *name,
			const char *def = nullptr) const
	{
		json_t *obj(json_object_get(json, name));
		if (!obj)
			return def;
		return json_string_value(obj);
	}
	inline int64_t GetInt(const char *name, int def = 0) const
	{
		json_t *obj(json_object_get(json, name));
		if (!obj)
			return def;
		return json_integer_value(obj);
	}
	inline json_t *GetObject(const char *name) const
	{
		return json_object_get(json, name);
	}

	inline json_t *get() const {return json;}
};

/* ------------------------------------------------------------------------ */

std::string vstrprintf(const char *format, va_list args);
std::string strprintf(const char *format, ...);
