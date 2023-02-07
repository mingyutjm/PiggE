#pragma once

#ifdef PIG_PLATFORM_WINDOWS
    #ifdef PIG_BUILD_DLL
        #define PIGGE_API __declspec(dllexport)
    #else
        #define PIGGE_API __declspec(dllimport)
    #endif
#endif
