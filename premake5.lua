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
IncludeDir["Glad"] = "PiggE/vendor/Glad/include"
IncludeDir["ImGui"] = "PiggE/vendor/imgui"


group "Dependencies"
    include "PiggE/vendor/GLFW"
    include "PiggE/vendor/Glad"
    include "PiggE/vendor/imgui"
group ""

project "PiggE"
    location "PiggE"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"
        defines { 
            "PIG_PLATFORM_WINDOWS",
            "PIG_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
        }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "PIG_DEBUG"
        -- buildoptions "/MDd"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        -- buildoptions "/MD"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
        -- buildoptions "/MD"
        runtime "Release"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        systemversion "latest"
        defines { 
            "PIG_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PIG_DEBUG"
        -- buildoptions "/MDd"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PIG_RELEASE"
        -- buildoptions "/MD"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PIG_DIST"
        -- buildoptions "/MD"
        runtime "Release"
        optimize "On"