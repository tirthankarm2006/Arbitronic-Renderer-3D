#pragma once
#include "Core/Logging/Log.h"
#include "Editor/Window/glfw_window.h"

namespace ARB {
	class Sandbox
	{
	protected:
		ARBWindow* m_window;
		virtual ~Sandbox(){}
	public:
		Sandbox();
		virtual void runApp() = 0;
	};
}