
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
       "$(SolutionDir)/_Renderer/src",
       "$(SolutionDir)/_Renderer/src/Core",
       "$(SolutionDir)/Utility/src",
       "$(SolutionDir)/3rdPartyLibs",
       "$(SolutionDir)/3rdPartyLibs/GLFW/include",
       "$(SolutionDir)/3rdPartyLibs/glad_OpenGL/include",
       "$(SolutionDir)/3rdPartyLibs/spdlog/include",
       "$(SolutionDir)/3rdPartyLibs/imgui/src/main/",
       "$(SolutionDir)/3rdPartyLibs/imgui/src/backend",
       "$(SolutionDir)/3rdPartyLibs/Glm",
       "$(SolutionDir)/3rdPartyLibs/fmt/include"
    }
    
    libdirs{
        "$(SolutionDir)3rdPartyLibs/fmt/build/Debug"
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
        "fmtd.lib",
        "Utility"
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