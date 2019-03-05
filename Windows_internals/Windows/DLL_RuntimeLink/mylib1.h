#pragma once
#ifdef DLL_RUNTIMELINK_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add_dll(int a, int b);
MYLIBAPI int subtract_dll(int a, int b);
MYLIBAPI int mul(int a, int b);
MYLIBAPI int divv(int a, int b);