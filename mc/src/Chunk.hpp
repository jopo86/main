#pragma once

#include "Block.hpp"

class Chunk {
public:
    Chunk(){}
    Chunk(glm::vec3 offset);

    void render();

    ~Chunk();

private:
    Block blocks[16][16][16];
    GLubyte block_types[16][16][16];
};