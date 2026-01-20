#include "ARBpch.h"
#include "OpenGLFramebuffer.h"

namespace ARB {
	void OpenGLFramebuffer::GenerateFrameBuffer() {
		if (IsFrameBufferIDValid()) {
			std::cout << "Framebuffer " << m_name << " object has already been created!!" << std::endl;
			return;
		}

		//Creating a framebuffer object
		glGenFramebuffers(1, &fbID.ID);
		fbID.isValid = true;
	}
	void OpenGLFramebuffer::GenerateColorBufferTexture() {
		if (IsColorBufferIDValid()) {
			std::cout << "Color Buffer presets of Framebuffer " << m_name << " has already been set!!" << std::endl;
			return;
		}

		//Color buffer texture
		glGenTextures(1, &colorBufferID.ID);
		glBindTexture(GL_TEXTURE_2D, colorBufferID.ID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_scrWidth, m_scrHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		colorBufferID.type = BufferType::OPENGL_COLOR_TEXTURE_BUFFER;
		colorBufferID.isValid = true;
	}
	void OpenGLFramebuffer::GenerateColorBufferRenderBuffer() {
		if (IsColorBufferIDValid()) {
			std::cout << "Color Buffer presets of Framebuffer " << m_name << " has already been set!!" << std::endl;
			return;
		}

		//Color Render Buffer
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateDepthBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateDepthBufferRenderBuffer() {
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateStencilBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateStencilBufferRenderBuffer() {
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateDepthStencilBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::GenerateDepthStencilBufferRenderBuffer() {
		if (IsDepthStencilBufferIDValid()) {
			std::cout << "Depth_Stencil Buffer presets of Framebuffer " << m_name << " has already been set!!" << std::endl;
		}

		glGenRenderbuffers(1, &depthStencilBufferID.ID);
		glBindRenderbuffer(GL_RENDERBUFFER, depthStencilBufferID.ID);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_scrWidth, m_scrHeight);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		depthStencilBufferID.isValid = true;
		depthStencilBufferID.type = BufferType::OPENGL_DEPTH_STENCIL_RENDERBUFFER;
	}
	void OpenGLFramebuffer::AttachColorBufferTexture() {
		if (IsColorBufferIDAttached())
			return;

		//Attaching the color buffer
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorBufferID.ID, 0);
		colorBufferID.isAttachedToFB = true;
	}
	void OpenGLFramebuffer::AttachColorBufferRenderBuffer() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachDepthBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachDepthBufferRenderBuffer() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachStencilBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachStencilBufferRenderBuffer() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachDepthStencilBufferTexture() {
		//To be implemented
	}
	void OpenGLFramebuffer::AttachDepthStencilBufferRenderBuffer() {
		if (IsDepthStencilBufferIDAttached())
			return;

		//Attaching the Depth Stencil buffer
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthStencilBufferID.ID);
		depthStencilBufferID.isAttachedToFB = true;
	}
	void OpenGLFramebuffer::BindFrameBuffer() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbID.ID);
	}
	void OpenGLFramebuffer::UnbindFrameBuffer() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	void OpenGLFramebuffer::BindColorTexture() {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, colorBufferID.ID);
	}
	void OpenGLFramebuffer::CheckStatus() {
		BindFrameBuffer();
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
		UnbindFrameBuffer();
	}
}