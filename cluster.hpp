#pragma once

#include <glm/vec3.hpp>

#include "cube.hpp"
#include "shader_manager.hpp"

class Cluster {
public:
	std::vector<Cube*> cubes;
public:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	float rotation = 0.0f;
	float scale = 1.0f;
public:
	Cluster();
	Cluster(glm::vec3 position, float rotation, float scale);
	~Cluster();
public:
	void appendCube(glm::vec3 offset);
	void generateCluster();
	void render(ShaderManager *shaderMan);
	void setPosition(glm::vec3 position);
	void setName(int i);
};