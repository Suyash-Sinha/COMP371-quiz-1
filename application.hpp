#pragma once

#include <GLFW/glfw3.h>

#include "arrow.hpp"
#include "camera.hpp"
#include "cluster.hpp"
#include "cube.hpp"
#include "grid.hpp"
#include "scheduler.hpp"
#include "shader_manager.hpp"
#include "wall.hpp"
#include "sky.hpp"

class Application {
public:
	double const UPDATE_INTERVAL = 1.0 / 30.0;
	int const WINDOW_SIZE[2] = {1024, 768};
	float const wallsize = 7;
	char const* WINDOW_TITLE = "COMP371-Quiz1-Suyash Sinha (40096587)";
	glm::vec3 INITIAL_CLUSTER_POSITIONS[5] = {
		glm::vec3(-2*wallsize,3.5f,0.0f),
		glm::vec3(-wallsize,3.5f,0.0f),
		glm::vec3(  0.0f,3.5f,0.0f),
		glm::vec3( wallsize,3.5f,0.0f),
		glm::vec3( 2*wallsize,3.5f,0.0f)
	};
public:
	Scheduler scheduler = Scheduler(UPDATE_INTERVAL);
	GLFWwindow* window = nullptr;
	glm::dvec2 lastMousePos = glm::dvec2(0, 0);
public:
	Sky* sky;
	Camera* camera;
	Grid* grid;
	ShaderManager *shaderMan;
	Cube *cube;
	Arrow *xAxis, *yAxis, *zAxis;
	
public:
	glm::vec2 worldRotation = glm::vec2(0, 0);
	Cluster *clusters;
	int currentCluster = 0;
	Wall **walls;
public:
	Application();
	~Application();
public:
	void handleMouse();
	void render();
	void update();
private:
	void initialiseGLFW();
	void initialiseOpenGL();
	void initialiseOpenGLShaders();
	void initialiseScene();
};