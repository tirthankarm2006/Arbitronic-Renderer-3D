
project "CoreTest1"
   kind "ConsoleApp"
   language "C++"

   targetdir ("binaries/%{prj.name}")
   objdir ("objs-int/%{prj.name}")

   files{
      "src/**.h",
      "src/**.cpp",
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

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		defines 
		{
			"_CRT_SECURE_NO_WARNINGS" --pre-defined macro to remove all warnings
		}

      links
      {
        "_ArbitronicRenderer3D",
        "GLFW", --linking the project with name "GLFW",
        "GLAD",
        "opengl32.lib",
        "spdlog",
        "imgui",
        "fmtd.lib",
        "Utility"
      }

      buildoptions
      {
         "/utf-8",
      }
      
   filter "configurations:Debug"
        defines "SANDBOX_DEBUG"
        kind "ConsoleApp"
        linkoptions { "/SUBSYSTEM:CONSOLE" }
        symbols "On"
        
    filter "configurations:Release"
        defines "SANDBOX_RELEASE"
        kind "WindowedApp"
        linkoptions { "/SUBSYSTEM:WINDOWS" }
        optimize "On"