#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include "shader_manager.hpp"
#include "render_object.hpp"

class Sky : RenderObject {
public:
	glm::vec3 position = glm::vec3(0, 0, 0);
public:
	Sky(glm::vec4 color, glm::vec3 position = glm::vec3(0, 0, 0));
	~Sky();
public:
	void render();
	void setPosition(glm::vec3 position);
};