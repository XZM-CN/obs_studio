//////////////////////////////////基本信息///////////////////////////////////////////////////////  
// ><免责声明 ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><创建日期 ><  2017/03/21  
// ><创建时间 ><  2017年:03月:21日   16时:37分:29秒  
// ><文件     ><  win-update-helpers.cpp  
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
// ><修改日期 ><  2017年:03月:21日   16时:37分:29秒  
// ><原因     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include "win-update-helpers.hpp"

void FreeProvider(HCRYPTPROV prov)
{
	CryptReleaseContext(prov, 0);
}

void FreeHash(HCRYPTHASH hash)
{
	CryptDestroyHash(hash);
}

void FreeKey(HCRYPTKEY key)
{
	CryptDestroyKey(key);
}

std::string vstrprintf(const char *format, va_list args)
{
	if (!format)
		return std::string();

	std::string str;
	int size = (int)vsnprintf(nullptr, 0, format, args);
	str.resize(size);
	vsnprintf(&str[0], size, format, args);
	return str;
}

std::string strprintf(const char *format, ...)
{
	std::string str;
	va_list args;

	va_start(args, format);
	str = vstrprintf(format, args);
	va_end(args);

	return str;
}
