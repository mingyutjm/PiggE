#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace PiggE {
    class PIGGE_API Log
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

// Core log macros
#define PIG_CORE_TRACE(...)     ::PiggE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PIG_CORE_INFO(...)      ::PiggE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PIG_CORE_WARN(...)      ::PiggE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PIG_CORE_ERROR(...)     ::PiggE::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define PIG_CORE_FATAL(...) ::PiggE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PIG_TRACE(...)   ::PiggE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PIG_INFO(...)    ::PiggE::Log::GetClientLogger()->info(__VA_ARGS__)
#define PIG_WARN(...)    ::PiggE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PIG_ERROR(...)   ::PiggE::Log::GetClientLogger()->error(__VA_ARGS__)
//#define PIG_CORE_FATAL(...)   ::PiggE::Log::GetClientLogger()->fatal(__VA_ARGS__)