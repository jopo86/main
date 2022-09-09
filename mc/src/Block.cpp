#include "Block.hpp"

Block::Block(GLfloat* type_vertices) {
    mesh = new Mesh((GLfloat*)type_vertices, static_indices, 120, 36);
}

Block::Block(GLfloat* type_vertices, glm::vec3 offset) {
    for (int i = 0; i < 120; i++) {
        if (i % 5 == 0) type_vertices[i] += offset.x;
        if (i % 5 == 1) type_vertices[i] += offset.y;
        if (i % 5 == 2) type_vertices[i] += offset.z;
    }
    mesh = new Mesh(type_vertices, static_indices, 120, 36);
}

void Block::render() {
    mesh->render();
}

Block::~Block() {

}
