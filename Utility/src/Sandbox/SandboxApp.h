#pragma once
#include "Editor/Window/glfw_window.h"
#include "Logging/Sandbox_Log.h"
#include "Core.h"

class SandboxApp
{
protected:
#ifdef _GLFW_USE_
	ARB::glfw_Window* m_window;
#endif
	virtual ~SandboxApp() {}
public:
	SandboxApp();
	void runApp();
};
