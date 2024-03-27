workspace "DigitalSchool"

    architecture "x86_64"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DigitalSchool"

    kind "ConsoleApp"
    
    language "C++"
    cppdialect "C++20"

    targetdir ("./bin/".. outputdir.. "/%{prj.name}")
    objdir ("./bin-int/".. outputdir.. "/%{prj.name}") 

    files { "./%{prj.name}/src/**.cpp", "./%{prj.name}/src/**.h" }

    includedirs { "./vendor/raylib/include", "./%{prj.name}/src" }

    libdirs { "./vendor/raylib/lib" }

    links { "raylibdll" }

    postbuildcommands { ("{COPY} ./vendor/raylib/lib/raylib.dll ./bin/".. outputdir.. "/%{prj.name}") }

    staticruntime "On"

    systemversion "latest"

    filter "configurations:Debug"
      defines "OD_DEBUG"
      symbols "On"
    
    filter "configurations:Release"
      defines "OD_RELEASE"
      optimize "On"