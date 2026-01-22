#pragma once

#ifndef _ARB_SHADER_H_
#define _ARB_SHADER_H_
#include "ARBpch.h"

namespace ARB {
	class ARBShader {
	public:
		enum class ARB_SHADER_TYPE : uint8_t {
			VERTEX = 0,
			FRAGMENT = 1,
			GEOMETRY = 2,
			COMPUTE = 3,
			TESSELATION = 4
		};
	protected:
		char* path;//With respect to the executable
		char* fullPath;//Full Path
		char* code;
		char* name;
		bool isCompiled;
		ARB_SHADER_TYPE type;
	public:
		virtual void LoadFromFilePath(char* filePath) = 0;
		virtual void LoadFromFilePathFull(const char* fullfilePath) = 0;
		virtual void AddName(char* name) { this->name = name; };
		virtual inline const char* GetName() { return (name != nullptr) ? name : nullptr; };
		virtual inline const char* GetPath() { return (path != nullptr) ? path : nullptr; };
		virtual inline const char* GetFullPath() { return (fullPath != nullptr) ? fullPath : nullptr; };
		virtual inline bool GetCompiledStatus() { return isCompiled; };
		virtual void Delete() = 0;
		virtual void Compile() = 0;
		virtual void ReCompile() = 0;
	};
}

#endif // !_ARB_SHADER_H_
