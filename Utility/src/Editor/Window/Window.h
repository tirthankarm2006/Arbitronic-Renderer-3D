#pragma once
#include "Logging/Log.h"

#ifndef _ARB_WINDOW_H_
#define _ARB_WINDOW_H_

namespace ARB {

	class ARBWindow {
	protected:
		template<typename T>
		struct WindowProps {
			WindowProps()
			    :m_handle(nullptr), m_width(640), m_height(480), m_name("_DEFAULT_WINDOW_") {}
			WindowProps(uint32_t width, uint32_t height, char* name)
				:m_handle(nullptr), m_width(width), m_height(height), m_name(name) {}
			WindowProps(T* handle, uint32_t width, uint32_t height, const char* name)
				:m_handle(handle), m_width(width), m_height(height), m_name(name) {}
			T* m_handle;
			uint32_t m_width, m_height;
			char* m_name;
		};

		typedef struct {
			uint32_t m_width, m_height;
			unsigned char* data;
		}WindowImage;

		WindowImage m_WinImage;

		ARBWindow() : m_WinImage({0, 0, nullptr}) {};
		virtual ~ARBWindow() {}
	public:
		virtual void GenerateWindow() {}
		virtual void processInput() {}
		virtual int windowShouldClose() { return 0; }
		virtual void onWindowClosed() {}
		virtual void startUpdate() {}
		virtual void endUpdate() {}
		virtual void ShowWindow() {}
		virtual void HideWindow() {}
		virtual void closeWindow() {}

		virtual inline uint32_t GetWindowWidth() = 0;
		virtual inline uint32_t GetWindowHeight() = 0;
		virtual inline const char* GetWindowName() = 0;

		virtual inline uint32_t GetImageWidth() { return m_WinImage.m_width; }
		virtual inline uint32_t GetImageHeight() { return m_WinImage.m_height; }
		virtual inline const unsigned char* GetImageData() { return m_WinImage.data; }
	};
}

#endif // !_ARB_WINDOW_H_

