#pragma once
#include "Shader.h"
#include "Core.h"
#include "Utils/Maths/MathsWrapper.h"

#ifndef _ARB_OPENGLSHADER_H_
#define _ARB_OPENGLSHADER_H_

#ifdef OPENGL_USE
#include "OpenGLWrapper.h"

namespace ARB {

	class OpenGLShader : public ARBShader
	{
	protected:
		typedef struct {
			std::vector<std::string> paramNames;
			std::vector<OPENGL_PARAM_LOC_TYPE> paramLocs;
			std::vector<OPENGL_ENUM_TYPE> paramType;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, float> floatParams;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, bool> boolParams;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, int> intParams;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, unsigned int> uintParams;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_VEC3> vec3Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_VEC4> vec4Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_VEC2> vec2Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_IVEC2> ivec2Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_IVEC3> ivec3Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_IVEC4> ivec4Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_UVEC2> uvec2Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_UVEC3> uvec3Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_UVEC4> uvec4Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_MATRIX3> matrix3Params;
			std::unordered_map<OPENGL_PARAM_LOC_TYPE, ARB_MATRIX4> matrix4Params;
		}ARBUniformShaderParams;

		ARBUniformShaderParams* params;

		virtual void CompileStatus() = 0;
		OPENGL_SHADER_OBJ_TYPE ID;

		virtual void LoadFromFilePath(char* filePath) override;
		virtual void LoadFromFilePathFull(const char* fullfilePath) override;
		virtual void Delete() override = 0;
		virtual void Compile() override = 0;
		virtual void ReCompile() override = 0;

		inline OPENGL_SHADER_OBJ_TYPE GetID() { return ID; }
	};
}

#endif // OPENGL_USE

#endif // !_ARB_OPENGLSHADER_H_

