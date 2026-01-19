
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
      "$(SolutionDir)Sandbox",
      "$(SolutionDir)Sandbox/src",
      "$(SolutionDir)Engine/src",
      "$(SolutionDir)Engine/3rdPartyLibs",
      "$(SolutionDir)Engine/3rdPartyLibs/GLFW/include",
      "$(SolutionDir)Engine/3rdPartyLibs/glad_OpenGL/include",
      "$(SolutionDir)Engine/3rdPartyLibs/spdlog/include",
      "$(SolutionDir)Engine/3rdPartyLibs/imgui/src/main/",
      "$(SolutionDir)Engine/3rdPartyLibs/imgui/src/backend",
      "$(SolutionDir)Engine/3rdPartyLibs/Glm",
      "$(SolutionDir)Engine/3rdPartyLibs/Assimp/include",
      "$(SolutionDir)Engine/3rdPartyLibs/Assimp/build/include",
      "$(SolutionDir)Engine/3rdPartyLibs/Assimp/build/include/assimp"
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
         "ArbitronicRenderer3D"
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