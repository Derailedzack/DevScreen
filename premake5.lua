workspace "DevScreen"
    configurations {"Debug","Release"}
    filter "configurations:Debug"
        defines {"DEBUG"}
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
project "DevScreen"
    kind "StaticLib"
    language "C"
    files{
        "*.c",
        "*.h"
    }
    
    includedirs("deps/GL/include")
    filter "system:windows"
       system("windows")
       architecture "x64"
       libdirs{
        "deps/SDL2/lib/x64",
        "deps/LUA/lib/x64/"
       }
       includedirs{
        "deps/SDL2/include",
        "deps/GL/include/glad"
       }
       links{"SDL2","lua51-Debug"}