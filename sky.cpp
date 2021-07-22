#include "sky.hpp"

Sky::Sky(glm::vec4 color, glm::vec3 position) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 4, GL_FLOAT, GL_FALSE) }) {
	this->position = position;
	GLfloat const s = 25;
	std::vector<GLfloat> vertices = {
		-s, -s, -s, color.x, color.y, color.z, color.w,
		s, -s, -s, color.x, color.y, color.z, color.w,
		s, s, -s, color.x, color.y, color.z, color.w,
		-s, s, -s, color.x, color.y, color.z, color.w,
		-s, -s, s, color.x, color.y, color.z, color.w,
		s, -s, s, color.x, color.y, color.z, color.w,
		s, s, s, color.x, color.y, color.z, color.w,
		-s, s, s, color.x, color.y, color.z, color.w
	};
	// Using an index array to not have to re-use vertices over and over again for triangles
	// that may share them. This saves up quite a bit of space (over 50% memory save).
	std::vector<GLuint> indices = {
		3, 1, 0,
		2, 1, 3,
		2, 5, 1,
		6, 5, 2,
		6, 4, 5,
		7, 4, 6,
		7, 0, 4,
		3, 0, 7,
		7, 2, 3,
		6, 2, 7,
		0, 5, 4,
		1, 5, 0
	};
	updateVertices(vertices);
	updateIndices(indices);
}
Sky::~Sky() {
	return;
}
void Sky::render() {
	RenderObject::render();
}
void Sky::setPosition(glm::vec3 position) {
	this->position = position;
}