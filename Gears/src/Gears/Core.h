#pragma once

#ifdef GR_PLATFORM_WINDOWS
	#ifdef GR_BUILD_DLL
		#define GEARS_API __declspec(dllexport)
	#else
		#define GEARS_API __declspec(dllimport)
	#endif
#else
	#error Gears only supports Windows!
#endif // GR_PLATFORM_WINDOWS

#ifdef GR_ENABLE_ASSERTS
	#define GR_ASSERT(x,...) {if(!(x)){GR_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
	#define GR_CORE_ASSERT(x,...) {if(!(x)){GR_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
	#define GR_ASSERT(x, ...)
	#define GR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)