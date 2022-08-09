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
