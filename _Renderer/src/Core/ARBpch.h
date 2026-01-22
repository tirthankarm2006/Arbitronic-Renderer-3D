#pragma once

#ifndef _ARBPCH_
#define _ARBPCH_

#include "windows.h"
#include "stdint.h"
#include "sstream"
#include <functional>
#include <string>
#include "memory"
#include <queue>
#include "mutex"
#include "iostream"
#include "fstream"
#include "memory"
//SPDLOG libs
#include "spdlog/spdlog.h"
#include "spdlog/details/log_msg.h"
#include "spdlog/sinks/base_sink.h"
#include "spdlog/pattern_formatter.h"
//GLM libs
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
//GLAD lib
#include "glad/glad.h"
//GLFW libs
#include "GLFW/glfw3.h"
//IMGUI libs
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
//STB libs
#include "stb/stb_image.h"
//FMT libs
#include "fmt/include/fmt/color.h"
#include "fmt/include/fmt/base.h"
#include "fmt/include/fmt/format.h"

//#include <assimp/camera.h>
//#include <assimp/mesh.h>
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>

#endif // !_ARBPCH_

