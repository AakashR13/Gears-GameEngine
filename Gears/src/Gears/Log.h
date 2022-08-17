#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Gears {

	class GEARS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//Core log macros
#define GR_CORE_TRACE(...)	::Gears::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GR_CORE_INFO(...)	::Gears::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GR_CORE_WARN(...)	::Gears::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GR_CORE_ERROR(...)	::Gears::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GR_CORE_FATAL(...)	::Gears::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define GR_TRACE(...)		::Gears::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GR_INFO(...)		::Gears::Log::GetClientLogger()->info(__VA_ARGS__)
#define GR_WARN(...)		::Gears::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GR_ERROR(...)		::Gears::Log::GetClientLogger()->error(__VA_ARGS__)
#define GR_FATAL(...)		::Gears::Log::GetClientLogger()->fatal(__VA_ARGS__)



