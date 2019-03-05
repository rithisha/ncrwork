#pragma once
#ifdef PROJECTDLL_EXPORTS
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif
MYLIBAPI int add(int a, int b);
MYLIBAPI int subtract(int a, int b);