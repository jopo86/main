#include "Block.hpp"

Block::Block(GLfloat* type_vertices) {
    this->block_type = BlockType::to_byte(type_vertices);
    if (!block_type) return;
    mesh = new Mesh(type_vertices, static_indices, 120, 36);
}

Block::Block(GLfloat* type_vertices, glm::vec3 offset) {
    GLfloat type_vertices_copy[120];
    for (int i = 0; i < 120; i++) {
        type_vertices_copy[i] = type_vertices[i];
    }
    this->block_type = BlockType::to_byte(type_vertices);
    if (!block_type) return;
    for (int i = 0; i < 120; i++) {
        if (i % 5 == 0) type_vertices_copy[i] += offset.x;
        if (i % 5 == 1) type_vertices_copy[i] += offset.y;
        if (i % 5 == 2) type_vertices_copy[i] += offset.z;
    }
    mesh = new Mesh(type_vertices_copy, static_indices, 120, 36);
}

void Block::render() {
    if (!block_type) return;
    mesh->render();
}

Block::~Block() {}
