#pragma once
#include "Arbitronic.h"
#include "Sandbox_Log.h"

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
