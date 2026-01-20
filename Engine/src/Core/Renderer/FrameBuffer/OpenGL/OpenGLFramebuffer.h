#pragma once
#include "Arbitronic.h"

#ifndef _ARB_OPENGL_FRAMEBUFFER_H_
#define _ARB_OPENGL_FRAMEBUFFER_H_

namespace ARB {
	class OpenGLFramebuffer
	{
	public:
		enum class BufferType : uint8_t {
			NO_TYPE = 0,
			OPENGL_COLOR_TEXTURE_BUFFER = 1,
			OPENGL_COLOR_RENDER_BUFFER = 2,
			OPENGL_DEPTH_TEXTURE_BUFFER = 3,
			OPENGL_DEPTH_RENDER_BUFFER = 4,
			OPENGL_STENCIL_TEXTURE_BUFFER = 5,
			OPENGL_STENCIL_RENDER_BUFFER = 6,
			OPENGL_DEPTH_STENCIL_TEXTURE = 7, //DEPTH24_STENCIL8
			OPENGL_DEPTH_STENCIL_RENDERBUFFER = 8 //DEPTH24_STENCIL8
		};
	private:
		struct OpenGLBufferID {
			OpenGLBufferID() : isValid(false), isAttachedToFB(false), type(BufferType::NO_TYPE), ID(0) {}
			uint32_t ID;
			bool isValid;
			bool isAttachedToFB;//Attached to Framebuffer or not
			BufferType type;
		};

		struct OpenGLFrameBufferObj {
			OpenGLFrameBufferObj() : isValid(false), ID(0) {}
			uint32_t ID;
			bool isValid;
		};

		OpenGLFrameBufferObj fbID;
		OpenGLBufferID colorBufferID;//Texture2D
		OpenGLBufferID depthBufferID, stencilBufferID;
		OpenGLBufferID depthStencilBufferID;//RenderBuffer(Depth=24, Stencil=8)
		uint32_t m_scrWidth, m_scrHeight;
		std::string m_name;
	public:
		OpenGLFramebuffer::OpenGLFramebuffer(std::string name = "Default_FB", uint32_t scrwidth = 1600, uint32_t scrheight = 900) :
			m_scrWidth(scrwidth), m_scrHeight(scrheight), m_name(name),
			fbID(OpenGLFrameBufferObj()), colorBufferID(OpenGLBufferID()),
			depthBufferID(OpenGLBufferID()), stencilBufferID(OpenGLBufferID()),
			depthStencilBufferID(OpenGLBufferID())
		{}

		void GenerateFrameBuffer();
		void GenerateColorBufferTexture();
		void GenerateColorBufferRenderBuffer();
		void GenerateDepthBufferTexture();
		void GenerateDepthBufferRenderBuffer();
		void GenerateStencilBufferTexture();
		void GenerateStencilBufferRenderBuffer();
		void GenerateDepthStencilBufferTexture();
		void GenerateDepthStencilBufferRenderBuffer();

		void BindFrameBuffer();
		void UnbindFrameBuffer();

		void AttachColorBufferTexture();
		void AttachColorBufferRenderBuffer();
		void AttachDepthBufferTexture();
		void AttachDepthBufferRenderBuffer();
		void AttachStencilBufferTexture();
		void AttachStencilBufferRenderBuffer();
		void AttachDepthStencilBufferTexture();
		void AttachDepthStencilBufferRenderBuffer();

		void BindColorTexture();//Will use GL_TEXTURE0
		void CheckStatus();

		inline uint32_t GetFBID() { return fbID.ID; }
		inline uint32_t GetColorBufferID() { return colorBufferID.ID; }
		inline uint32_t GetDepthBufferID() { return depthBufferID.ID; }
		inline uint32_t GetStencilBufferID() { return stencilBufferID.ID; }
		inline uint32_t GetDepthStencilBufferID() { return depthStencilBufferID.ID; }

		inline bool IsFrameBufferIDValid() { return fbID.isValid; }
		inline bool IsColorBufferIDValid() { return colorBufferID.isValid; }
		inline bool IsDepthBufferIDValid() { return depthBufferID.isValid; }
		inline bool IsStencilBufferIDValid() { return stencilBufferID.isValid; }
		inline bool IsDepthStencilBufferIDValid() { return depthStencilBufferID.isValid; }

		inline bool IsColorBufferIDAttached() { return colorBufferID.isAttachedToFB; }
		inline bool IsDepthBufferIDAttached() { return depthBufferID.isAttachedToFB; }
		inline bool IsStencilBufferIDAttached() { return stencilBufferID.isAttachedToFB; }
		inline bool IsDepthStencilBufferIDAttached() { return depthStencilBufferID.isAttachedToFB; }

		inline std::string GetFrameBufferName() { return m_name; }
	};
}

#endif // !_ARB_OPENGL_FRAMEBUFFER_H_

