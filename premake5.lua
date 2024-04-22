workspace "DigitalSchool"

    architecture "x86_64"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Create a static library project for Business Logic Layer (BLL)
project "BLL"
    location "BLL/BLL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "BLL/src/**.cpp", "BLL/include/**.h" }

    includedirs { "BLL/include" }

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
    location "DAL/DAL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/".. outputdir.. "/%{prj.name}")
    objdir ("bin-int/".. outputdir.. "/%{prj.name}")

    files { "DAL/src/**.cpp", "DAL/include/**.h" }

    includedirs { "DAL/include" }

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

    files { "DigitalSchool/src/**.cpp", "DigitalSchool/src/**.h" }

    includedirs { "vendor/raylib/include", "DigitalSchool/src", "BLL/include", "DAL/include" }

    libdirs { "vendor/raylib/lib" }

    links { "raylibdll", "BLL", "DAL" }

    postbuildcommands { ("{COPY} vendor/raylib/lib/raylib.dll bin/".. outputdir.. "/%{prj.name}") }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"
