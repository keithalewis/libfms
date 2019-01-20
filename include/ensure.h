// ensure.h - Like assert but calls debugger breakpoint. Define NENSURE to disable, ENSURE_ASSERT to call assert.
#pragma once
#include <cassert>

#if defined(NENSURE)
	#define ensure(x)
#elif defined(ENSURE_ASSERT)
#include <cassert>
	#define ensure(x) assert(x)
#elif defined(_MSC_VER)
void __stdcall __debugbreak(void);
	#define ensure(x) __debugbreak()
#elif defined(__GNUC__)
	#define ensure(x) __builtin_trap()
#elif defined(__clang__)
	#define ensure(x) __builtin_debugtrap()
#else
int raise(int);
	#define ensure(x) raise(SIGTRAP);
#endif

