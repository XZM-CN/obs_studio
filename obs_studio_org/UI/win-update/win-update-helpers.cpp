//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:37��:29��  
// ><�ļ�     ><  win-update-helpers.cpp  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\UI\win-update  
// ><��������><   obs-studio  
// ><��ǰ�û� ><  Administrator  
// ><����     ><  Open Broadcaster Software   
// ><����     >< �� https://obsproject.com/ ��  
// ><Ŀ��     >< ����  
// ><��Ƽ��� ><   
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
// ><         ><  4.  
//////////////////////////////////�����޸�///////////////////////////////////////////////////////  
// ><����     ><  xzm  
// ><�޸����� ><  2017��:03��:21��   16ʱ:37��:29��  
// ><ԭ��     ><    
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
