#pragma once

#ifdef PIG_PLATFORM_WINDOWS
    #ifdef PIG_BUILD_DLL
        #define PIGGE_API __declspec(dllexport)
    #else
        #define PIGGE_API __declspec(dllimport)
    #endif
#endif

#ifdef PIG_DEBUG
    #define PIG_ENABLE_ASSERTS
#endif

#ifdef PIG_ENABLE_ASSERTS
    #define PIG_ASSERT(x, ...) { if(!(x)) { PIG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define PIG_CORE_ASSERT(x, ...) { if(!(x)) { PIG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define PIG_ASSERT(x, ...)
    #define PIG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define PIG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)