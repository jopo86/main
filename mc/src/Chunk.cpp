#include "Chunk.hpp"

Chunk::Chunk(glm::vec3 offset) {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                block_types[x][y][z] = (y < 15) ? 2 : 1;
                blocks[x][y][z] = Block(BlockType::to_block_type(block_types[x][y][z]), glm::vec3(x, y, z));
            }
        }
    }
}

void Chunk::render() {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {
                blocks[x][y][z].render();
            }
        }
    }
}

Chunk::~Chunk() {}
