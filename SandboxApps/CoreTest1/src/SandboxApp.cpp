#include "SandboxApp.h"
#include "iostream"

SandboxApp::SandboxApp() {
	ARB_SANDBOX_INFO("hello, i am from inside sandbox project");

#ifdef _GLFW_USE_
    m_window = new ARB::glfw_Window(1280, 720, "My dear project");
#endif // _GLFW_USE_

	m_window->GenerateWindow();
	m_window->ShowWindow();
}

void SandboxApp::runApp(){
	while (!m_window->windowShouldClose()) {
		m_window->endUpdate();
	}
	m_window->onWindowClosed();
}
