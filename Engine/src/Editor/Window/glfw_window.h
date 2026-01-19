#pragma once
#include "Core/Logging/Log.h"
#include "Window.h"
#include "Core/Core.h"

#ifndef _ARB_WIN32_WINDOW_H_
#define _ARB_WIN32_WINDOW_H_

#ifdef _GLFW_USE_

namespace ARB {
	class glfw_Window : public ARBWindow {
	public:
		void GenerateWindow() override;
		void processInput() override;
		int windowShouldClose() override;
		void onWindowClosed() override;
		void startUpdate() override;
		void endUpdate() override;
		void ShowWindow() override;
		void HideWindow() override;
		void closeWindow() override;
	private:
		WindowProps<GLFWwindow> mainWindow;
	public:
		virtual inline uint32_t GetWindowWidth() override { return mainWindow.m_width; }
		virtual inline uint32_t GetWindowHeight() override { return mainWindow.m_height; }
		virtual inline const char* GetWindowName() override { return mainWindow.m_name; }

		glfw_Window(unsigned int, unsigned int, char*);
		glfw_Window() : ARBWindow() {}
		~glfw_Window();
	};
}

#endif

#endif // !_ARB_WINDOW_H_
