include "3rdPartyLibs/GLFW"
include "3rdPartyLibs/glad_OpenGL"
include "3rdPartyLibs/spdlog"
include "3rdPartyLibs/imgui"
include "3rdPartyLibs/stb"

project "_ArbitronicRenderer3D"
    kind "StaticLib"
    language "C++"

    targetdir ("binaries/Main")
    objdir    ("binaries/objs_int")

    files{
        "src/**.h",
        "src/**.cpp",
        "src/**.c"
    }

    includedirs{
       "$(SolutionDir)Engine/src/",
       "$(SolutionDir)Engine/src/Core",
       "$(SolutionDir)Engine/src/Editor",
       "$(SolutionDir)Engine/src/Core/Renderer",
       "$(SolutionDir)Engine/src/Core/Renderer/Shader",
       "$(SolutionDir)Engine/3rdPartyLibs",
       "$(SolutionDir)Engine/3rdPartyLibs/GLFW/include",
       "$(SolutionDir)Engine/3rdPartyLibs/glad_OpenGL/include",
       "$(SolutionDir)Engine/3rdPartyLibs/spdlog/include",
       "$(SolutionDir)Engine/3rdPartyLibs/imgui/src/main/",
       "$(SolutionDir)Engine/3rdPartyLibs/imgui/src/backend",
       "$(SolutionDir)Engine/3rdPartyLibs/Glm",
       "$(SolutionDir)Engine/3rdPartyLibs/fmt/include"
       --"$(SolutionDir)Engine/3rdPartyLibs/Assimp/include",
       --"$(SolutionDir)Engine/3rdPartyLibs/Assimp/build/include",
       --"$(SolutionDir)Engine/3rdPartyLibs/Assimp/build/include/assimp"
    }
    
    libdirs{
        --"$(SolutionDir)Engine/3rdPartyLibs/Assimp/build/lib/Debug"
        "$(SolutionDir)Engine/3rdPartyLibs/fmt/build/Debug"
    }

    pchheader "ARBpch.h"
    pchsource "src/Core/ARBpch.cpp"

    links
    {
        "GLFW", --linking the project with name "GLFW",
        "GLAD",
        "opengl32.lib",
        "spdlog",
        "imgui",
        "fmtd.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        buildoptions
        {
            "/utf-8"
        }

    filter "configurations:Debug"
        defines "ARB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ARB_RELEASE"
        optimize "On"