-- Create the solution file
workspace "DigitalSchool"
    startproject "DigitalSchool"
    architecture "x86_64"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Create a static library project for Business Logic Layer (BLL)
project "BLL"
    location "BLL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "BLL/src/**.cpp", "BLL/lib/**.h" }
    
    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"

-- Create a static library project for Data Access Layer (DAL)
project "DAL"
    location "DAL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "DAL/src/**.cpp", "DAL/lib/**.h" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"

-- Main application project
project "DigitalSchool"
    location "DigitalSchool"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "DigitalSchool/src/**.cpp", "DigitalSchool/lib/**.h" }

    includedirs { "vendor/raylib/include", "DigitalSchool/src", "BLL/lib", "DAL/lib" }

    libdirs { "vendor/raylib/lib" }

    links { "raylibdll", "BLL", "DAL" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"