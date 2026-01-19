#include "ARBpch.h"
#include "Sandbox.h"
#include "Core.h"

namespace ARB {
	Sandbox::Sandbox() {
		ARB_TRACE("HELLO");

		//Creating the window for the Sandbox
#ifdef _GLFW_USE_
		m_window = new glfw_Window(1280, 720, "Sandbox_Window");
		m_window->GenerateWindow();
#endif
	}
}