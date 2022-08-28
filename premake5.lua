workspace "Gears"
    architecture "x64"
    startproject "Sandbox"
    configurations
    { "Debug", "Release","Dist" }
    
outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Gears/vendor/GLFW/include"
IncludeDir["Glad"] = "Gears/vendor/Glad/include"
IncludeDir["ImGui"] = "Gears/vendor/imgui" 

include "Gears/vendor/GLFW"
include "Gears/vendor/Glad"
include "Gears/vendor/imgui"

project "Gears"
    location "Gears"
    kind "SharedLib"
    language "C++"
    staticruntime "off"
	
    targetdir("bin/" ..outputdir .. "/%{prj.name}")
    objdir("bin-int/" ..outputdir .. "/%{prj.name}")

    pchheader "grpch.h"
    pchsource "Gears/src/grpch.cpp"

    files
    {
        "%{prj.name}/src/**.h ",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"

    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "GR_PLATFORM_WINDOWS",
            "GR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GR_RELEASE"
        runtime "Release"
        symbols "On"
        
    filter "configurations:Dist"
        defines "GR_DIST"
        runtime "Release"
        symbols "On"


    
project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        staticruntime "off"
		
        targetdir("bin/" ..outputdir .. "/%{prj.name}")
        objdir("bin-int/" ..outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h ",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Gears/vendor/spdlog/include",
        "Gears/src"
    }

    links
    {
        "Gears"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "GR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GR_RELEASE"
        runtime "Release"
        symbols "On"
        
    filter "configurations:Dist"
        defines "GR_DIST"
        runtime "Release"
        symbols "On"
