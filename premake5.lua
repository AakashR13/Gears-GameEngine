workspace "Gears"
    architecture "x64"
    startproject "Sandbox"
    configurations
    { "Debug", "Release","Dist" }
    
outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Gears"
    location "Gears"
    kind "SharedLib"
    language "C++"


    targetdir("bin/" ..outputdir .. "/%{prj.name}")
    objdir("bin-int/" ..outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h ",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GR_PLATFORM_WINDOWS",
            "GR_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GR_RELEASE"
        symbols "On"
        
    filter "configurations:Dist"
        defines "GR_DIST"
        symbols "On"


    
project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

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
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GR_RELEASE"
        symbols "On"
        
    filter "configurations:Dist"
        defines "GR_DIST"
        symbols "On"
