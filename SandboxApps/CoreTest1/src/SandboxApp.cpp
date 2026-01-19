#include "SandboxApp.h"
#include "iostream"
#include "Core/Sandbox/Sandbox_Log.h"

SandboxApp::SandboxApp() : ARB::Sandbox() {
	ARB_SANDBOX_INFO("hello, i am from inside sandbox project");

	m_window->ShowWindow();
}

void SandboxApp::runApp(){
	while (!m_window->windowShouldClose()) {
		m_window->endUpdate();
	}
	m_window->onWindowClosed();
}
