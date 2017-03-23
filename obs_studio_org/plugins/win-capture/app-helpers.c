//////////////////////////////////������Ϣ///////////////////////////////////////////////////////  
// ><�������� ><  Copyright (c) 2017-2017 by Xie Zhimin All Rights Reserved  
// ><�������� ><  2017/03/21  
// ><����ʱ�� ><  2017��:03��:21��   16ʱ:57��:14��  
// ><�ļ�     ><  app-helpers.c  
// ><�ļ�·�� ><  D:\newSvnCode\OBS\trunk\obs_studio\plugins\win-capture  
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
// ><�޸����� ><  2017��:03��:21��   16ʱ:57��:14��  
// ><ԭ��     ><    
// ><         ><  1.  
// ><         ><  2.  
// ><         ><  3.  
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include "app-helpers.h"
#include "nt-stuff.h"

WINADVAPI WINAPI ConvertSidToStringSidW(PSID sid, LPWSTR *str);

bool is_app(HANDLE process)
{
	DWORD size_ret;
	DWORD ret = 0;
	HANDLE token;

	if (OpenProcessToken(process, TOKEN_QUERY, &token)) {
		BOOL success = GetTokenInformation(token, TokenIsAppContainer,
				&ret, sizeof(ret), &size_ret);
		if (!success) {
			DWORD error = GetLastError();
			int test = 0;
		}

		CloseHandle(token);
	}
	return !!ret;
}

wchar_t *get_app_sid(HANDLE process)
{
	wchar_t *ret = NULL;
	DWORD size_ret;
	BOOL success;
	HANDLE token;

	if (OpenProcessToken(process, TOKEN_QUERY, &token)) {
		DWORD info_len = GetSidLengthRequired(12) +
			sizeof(TOKEN_APPCONTAINER_INFORMATION);

		PTOKEN_APPCONTAINER_INFORMATION info = malloc(info_len);

		success = GetTokenInformation(token, TokenAppContainerSid,
				info, info_len, &size_ret);
		if (success)
			ConvertSidToStringSidW(info->TokenAppContainer, &ret);

		free(info);
		CloseHandle(token);
	}

	return ret;
}

static const wchar_t *path_format =
	L"\\Sessions\\%lu\\AppContainerNamedObjects\\%s\\%s";

HANDLE open_app_mutex(const wchar_t *sid, const wchar_t *name)
{
	wchar_t path[MAX_PATH];
	DWORD session_id = WTSGetActiveConsoleSessionId();
	_snwprintf(path, MAX_PATH, path_format, session_id, sid, name);
	return nt_open_mutex(path);
}

HANDLE open_app_event(const wchar_t *sid, const wchar_t *name)
{
	wchar_t path[MAX_PATH];
	DWORD session_id = WTSGetActiveConsoleSessionId();
	_snwprintf(path, MAX_PATH, path_format, session_id, sid, name);
	return nt_open_event(path);
}

HANDLE open_app_map(const wchar_t *sid, const wchar_t *name)
{
	wchar_t path[MAX_PATH];
	DWORD session_id = WTSGetActiveConsoleSessionId();
	_snwprintf(path, MAX_PATH, path_format, session_id, sid, name);
	return nt_open_map(path);
}
