#pragma once
#include "OpenGLShader.h"

#ifndef _ARB_OPENGLVERTEXSHADER_H_
#define _ARB_OPENGLVERTEXSHADER_H_

namespace ARB {
	class OpenGLVertexShader: public OpenGLShader
	{
	public:
		OpenGLVertexShader() { }
		virtual void Delete() override;
		virtual void Compile() override;
		virtual void ReCompile() override;

		virtual void CompileStatus() override;
	};
}

#endif // !_ARB_OPENGLVERTEXSHADER_H_