#include "ARBpch.h"
#include "OpenGLFramebuffer.h"

namespace ARB {
	void OpenGLFramebuffer::GenerateFrameBuffer() {
		if (IsFrameBufferIDValid()) {
			ARB_TRACE("Framebuffer {0}, object has already created", m_name);
			return;
		}

		//Creating a framebuffer object
		glGenFramebuffers(1, &fbID.ID);
		fbID.isValid = true;
	}
	void OpenGLFramebuffer::GenerateColorBufferTexture() {
		if (IsColorBufferIDValid()) {
			ARB_TRACE("Color Buffer presets of Framebuffer {0} has already been set", m_name);
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
			ARB_TRACE("Color Buffer presets of Framebuffer {0} has already been set", m_name);
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
			ARB_TRACE("Depth_Stencil Buffer presets of Framebuffer {0} has already been set");
		}

		glGenRenderbuffers(1, &depthStencilBufferID.ID);
		glBindRenderbuffer(GL_RENDERBUFFER, depthStencilBufferID.ID);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_scrWidth, m_scrHeight);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		depthStencilBufferID.type = BufferType::OPENGL_DEPTH_STENCIL_RENDERBUFFER;
		depthStencilBufferID.isValid = true;
	}
	void OpenGLFramebuffer::AttachColorBufferTexture() {
		if (colorBufferID.isAttachedToFB) {
			ARB_TRACE("A Color Buffer is already bound");
			return;
		}

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
		if (depthStencilBufferID.isAttachedToFB){
			ARB_TRACE("A Depth_Stencil Buffer is already bound");
			return;
		}

		//Attaching the Depth Stencil buffer
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depthStencilBufferID.ID);
		depthStencilBufferID.isAttachedToFB = true;
		ARB_TRACE("Depth_Stencil buffer as a RenderBuffer is bound");
	}
	void OpenGLFramebuffer::BindFrameBuffer() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbID.ID);
		ARB_TRACE("Framebuffer with ID {0} is now bound", fbID.ID);
	}
	void OpenGLFramebuffer::UnbindFrameBuffer() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		ARB_TRACE("Framebuffer at Index 0 is now bound");
	}
	void OpenGLFramebuffer::BindColorTexture() {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, colorBufferID.ID);
		ARB_TRACE("Color Buffer as a Texture is bound");
	}
	void OpenGLFramebuffer::CheckStatus() {
		BindFrameBuffer();
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			ARB_ERROR("Framebuffer is NOT Complete!");
		else
			ARB_INFO("Framebuffer is Complete!");
		UnbindFrameBuffer();
	}
}