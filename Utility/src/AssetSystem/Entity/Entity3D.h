#pragma once
#include "ARBpch.h"
#include "Logging/Log.h"

#ifndef _ARB_ENTITY3D_H_
#define _ARB_ENTITY3D_H_

namespace ARB {
	class Entity3D
	{
	protected:
		glm::vec3 m_position;
		std::string m_name;
		glm::vec3 m_scale;
		Entity3D(std::string name = "_ARB_DEFAULT_ENTITY3D", glm::vec3 pos = glm::vec3(0.0, 0.0, 0.0), glm::vec3 scale = glm::vec3(1.0, 1.0, 1.0))
			: m_position(pos), m_name(name), m_scale(scale) {
		}
		virtual void render() { }
		virtual void setPos(glm::vec3 pos) { m_position = pos; }
		virtual inline glm::vec3 getPos() { return m_position; }
		virtual void setName(std::string name) { m_name = name; }
		virtual inline std::string getName() { return m_name; }
		virtual void setScale(glm::vec3 scale) { m_scale = scale; }
		virtual glm::vec3 getScale() { return m_scale; }
	};
}

#endif // !_ARB_ENTITY3D_H_