#pragma once
#include "OpenGLShader.h"

#ifndef _ARB_OPENGLCOMPUTESHADER_H_
#define _ARB_OPENGLCOMPUTESHADER_H_

namespace ARB {
	class OpenGLComputeShader : public OpenGLShader
	{
	public:
		ARB_VEC3 invocationSize;
		ARB_VEC3 workGroupSize;
		OpenGLComputeShader() { }
		virtual void Delete() override;
		virtual void Compile() override;
		virtual void ReCompile() override;

		virtual void CompileStatus() override;
	};
}

#endif // !_ARB_OPENGLVERTEXSHADER_H_