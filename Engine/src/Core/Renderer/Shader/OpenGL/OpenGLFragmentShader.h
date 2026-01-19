#pragma once
#include "OpenGLShader.h"

#ifndef _ARB_OPENGLFRAGMENTSHADER_H_
#define _ARB_OPENGLFRAGMENTSHADER_H_

namespace ARB {
	class OpenGLFragmentShader : public OpenGLShader
	{
	public:
		OpenGLFragmentShader() {}
		virtual void Delete() override;
		virtual void Compile() override;
		virtual void ReCompile() override;

		virtual void CompileStatus() override;
	};
}

#endif // !_ARB_OPENGLVERTEXSHADER_H_