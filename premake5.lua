workspace "PiggE"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PiggE"
    location "PiggE"
    kind "SharedLib"
    language "C++"

    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
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
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
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
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
        optimize "On"