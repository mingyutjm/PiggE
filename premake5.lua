workspace "PiggE"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "PiggE/vendor/GLFW/include"

include "PiggE/vendor/GLFW"

project "PiggE"
    location "PiggE"
    kind "SharedLib"
    language "C++"

    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pigpch.h"
    pchsource "PiggE/src/pigpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        defines { 
            "PIG_PLATFORM_WINDOWS",
            "PIG_BUILD_DLL"
        }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} " .. " ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PIG_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
        -- buildoptions "/MD"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "PiggE/vendor/spdlog/include",
        "PiggE/src"
    }

    links {
        "PiggE"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        defines { 
            "PIG_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PIG_DEBUG"
        -- buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        -- buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
        -- buildoptions "/MD"
        optimize "On"