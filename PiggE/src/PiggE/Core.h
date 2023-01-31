#pragma once

#ifdef PE_PLATFORM_WINDOWS
    #ifdef PE_BUILD_DLL
        #define PIGGE_API __declspec(dllexport)
    #else
        #define PIGGE_API __declspec(dllimport)
    #endif
#endif
