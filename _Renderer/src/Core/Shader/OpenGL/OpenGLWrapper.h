#pragma once

#ifndef _ARB_OPENGLWRAPPER_H
#define _ARB_OPENGLWRAPPER_H

#define OPENGL_SHADER_OBJ_TYPE unsigned int
#define OPENGL_TEXTURE_OBJ_TYPE unsigned int
#define OPENGL_SHADER_PROGRAM_TYPE unsigned int
#define OPENGL_BIND_SHADER_PROGRAM(ID) glUseProgram(ID)
#define OPENGL_PARAM_LOC_TYPE int
#define OPENGL_ENUM_TYPE GLenum

namespace ARB {
	class OpenGLWrapper
	{
	public:
		static OPENGL_TEXTURE_OBJ_TYPE CreateSingle2DTextureID() {
			OPENGL_TEXTURE_OBJ_TYPE ID;
			glCreateTextures(GL_TEXTURE_2D, 1, &ID);
			return ID;
		}
	};
}

#endif // !_ARB_OPENGLWRAPPER_H

