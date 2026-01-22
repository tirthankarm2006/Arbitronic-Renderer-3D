#pragma once
#include "OpenGLShader.h"
#include "OpenGLFragmentShader.h"
#include "OpenGLVertexShader.h"
#include "OpenGLComputeShader.h"
#include "OpenGLWrapper.h"

#ifndef _ARB_OPENGLSHADERPROGRAM_H_
#define _ARB_OPENGLSHADERPROGRAM_H_

namespace ARB {
	class OpenGLShaderProgram
	{
	private:
		OpenGLFragmentShader* fragShader;
		OpenGLVertexShader* vertShader;
		OPENGL_SHADER_PROGRAM_TYPE ID;
	public:
		//Functions to set uniform parameters to shaders

	};
}

#endif // !_ARB_OPENGLSHADERPROGRAM_H_