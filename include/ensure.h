// ensure.h - Like assert but calls debugger breakpoint. Define NENSURE to disable, ENSURE_ASSERT to call assert.
#pragma once
#include <cassert>

#if defined(NENSURE)
	#define ensure(x)
#elif defined(ENSURE_ASSERT)
	#include <cassert>
	#define ensure(x) assert(x)
#elif defined(_MSC_VER)
	#include <intrin.h>
	#define ensure(x) if (!(x)) __debugbreak(); else (void)0;
#elif defined(__GNUC__)
	#define ensure(x) if (!(x)) __builtin_trap(); else (void)0;
#elif defined(__clang__)
	#define ensure(x) if (!(x)) __builtin_debugtrap(); else (void)0;
#else
	int raise(int);
	#define ensure(x) if (!(x)) raise(SIGTRAP); else (void)0;
#endif

