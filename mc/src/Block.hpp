#pragma once

#include <vector>

#include "Mesh.hpp"
#include "Tex2D.hpp"
#include "BlockType.hpp"

#include <glm/glm.hpp>

class Block {
public:
    Block(){};
    Block(GLfloat* type_vertices);
    Block(GLfloat* type_vertices, glm::vec3 offset);

    void render();

    ~Block();

private:
    Mesh* mesh;

    GLubyte block_type;

    std::vector<GLubyte> indices;

    GLubyte static_indices[36] = {
        0x00,0x01,0x02,
        0x00,0x03,0x02,
        0x04,0x05,0x06,
        0x04,0x07,0x06,
        0x08,0x09,0x0a,
        0x08,0x0b,0x0a,
        0x0c,0x0d,0x0e,
        0x0c,0x0f,0x0e,
        0x10,0x11,0x12,
        0x10,0x13,0x12,
        0x14,0x15,0x16,
        0x14,0x17,0x16,
    };
};