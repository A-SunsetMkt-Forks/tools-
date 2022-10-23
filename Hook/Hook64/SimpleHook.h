#ifndef __SIMPLEHOOK_H__
#define __SIMPLEHOOK_H__

#include<Windows.h>
#include<vector>

#ifndef SIMPLE_LIB
#ifndef _WIN64
#pragma comment(lib, "../Share/Hook/Hook.lib")
#else
#pragma comment(lib, "../Share/Hook/Hook64.lib")
#endif
#else
#endif

namespace SimpleHook {
	bool Hook(void *HookFunction, void *FunctionPointer, ULONG_PTR Address, ULONG_PTR OverWrite = 0);
	bool InlineHook(void *HookFunction, ULONG_PTR Address, DWORD dwStackValue);
	bool UnHook();
	bool Analyze(ULONG_PTR uAddress, std::vector<BYTE> &vCodeSize, ULONG_PTR uMinimumSize = 14);
}

// API�t�b�N
#define SHook(api) \
{\
	if(!SimpleHook::Hook(api##_Hook, &_##api, (ULONG_PTR)##api)) {\
		MessageBoxW(NULL, L""#api, L"NG", MB_OK);\
	}\
}

// DLL���w�肷��API�t�b�N
#define SHookNT(dll, api) \
{\
	HMODULE hModule = GetModuleHandleW(L""#dll);\
	if (hModule) {\
		ULONG_PTR uAddress = (ULONG_PTR)GetProcAddress(hModule, ""#api);\
		if (uAddress) {\
			if(!SimpleHook::Hook(api##_Hook, &_##api, uAddress)) {\
				MessageBoxW(NULL, L""#api, L"NG", MB_OK);\
			}\
		}\
	}\
}

// �A�h���X���w�肷��t�b�N
#define SHookFunction(name, address) \
{\
	if(!SimpleHook::Hook(name##_Hook, &_##name, address)) {\
		MessageBoxW(NULL, L""#name, L"NG", MB_OK);\
	}\
}

#endif