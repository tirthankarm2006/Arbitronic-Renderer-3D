workspace "ARBITRONIC_RENDERER_3D"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }
--All the 3rd party dependencies
include "3rdPartyLibs/GLFW"
include "3rdPartyLibs/glad_OpenGL"
include "3rdPartyLibs/spdlog"
include "3rdPartyLibs/imgui"
include "3rdPartyLibs/stb"

--Other utilities(not part of the renderer)
include "Utility"
--The Renderer
include "_Renderer"
--The Sandbox projects
include "SandboxApps/CoreTest1"