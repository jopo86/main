#include "BlockType.hpp"

const std::map<GLfloat*, GLubyte> BlockType::byte_map = {
    std::pair<GLfloat*, GLubyte>(0, 0x00),
    std::pair<GLfloat*, GLubyte>(BlockType::Grass,          0x01),
    std::pair<GLfloat*, GLubyte>(BlockType::Dirt,           0x02),
    std::pair<GLfloat*, GLubyte>(BlockType::Stone,          0x03),
    std::pair<GLfloat*, GLubyte>(BlockType::Sand,           0x04),
    std::pair<GLfloat*, GLubyte>(BlockType::OakPlanks,      0x05),
    std::pair<GLfloat*, GLubyte>(BlockType::DarkOakPlanks,  0x06),
    std::pair<GLfloat*, GLubyte>(BlockType::SprucePlanks,   0x07),
    std::pair<GLfloat*, GLubyte>(BlockType::BirchPlanks,    0x08),
    std::pair<GLfloat*, GLubyte>(BlockType::JunglePlanks,   0x09),
    std::pair<GLfloat*, GLubyte>(BlockType::AcaciaPlanks,   0x0a),
    std::pair<GLfloat*, GLubyte>(BlockType::OakLog,         0x0b),
    std::pair<GLfloat*, GLubyte>(BlockType::DarkOakLog,     0x0c),
    std::pair<GLfloat*, GLubyte>(BlockType::SpruceLog,      0x0d),
    std::pair<GLfloat*, GLubyte>(BlockType::BirchLog,       0x0e),
    std::pair<GLfloat*, GLubyte>(BlockType::JungleLog,      0x0f),
    std::pair<GLfloat*, GLubyte>(BlockType::AcaciaLog,      0x10),
    std::pair<GLfloat*, GLubyte>(BlockType::OakLeaves,      0x11),
    std::pair<GLfloat*, GLubyte>(BlockType::DarkOakLeaves,  0x12),
    std::pair<GLfloat*, GLubyte>(BlockType::SpruceLeaves,   0x13),
    std::pair<GLfloat*, GLubyte>(BlockType::BirchLeaves,    0x14),
    std::pair<GLfloat*, GLubyte>(BlockType::JungleLeaves,   0x15),
    std::pair<GLfloat*, GLubyte>(BlockType::AcaciaLeaves,   0x16),
    std::pair<GLfloat*, GLubyte>(BlockType::Water,          0x17),
    std::pair<GLfloat*, GLubyte>(BlockType::Lava,           0x18),
};

const std::map<GLubyte, GLfloat*> BlockType::block_type_map = {
    std::pair<GLubyte, GLfloat*>(0x00, 0),
    std::pair<GLubyte, GLfloat*>(0x01, BlockType::Grass),
    std::pair<GLubyte, GLfloat*>(0x02, BlockType::Dirt),
    std::pair<GLubyte, GLfloat*>(0x03, BlockType::Stone),
    std::pair<GLubyte, GLfloat*>(0x04, BlockType::Sand),
    std::pair<GLubyte, GLfloat*>(0x05, BlockType::OakPlanks),
    std::pair<GLubyte, GLfloat*>(0x06, BlockType::DarkOakPlanks),
    std::pair<GLubyte, GLfloat*>(0x07, BlockType::SprucePlanks),
    std::pair<GLubyte, GLfloat*>(0x08, BlockType::BirchPlanks),
    std::pair<GLubyte, GLfloat*>(0x09, BlockType::JunglePlanks),
    std::pair<GLubyte, GLfloat*>(0x0a, BlockType::AcaciaPlanks),
    std::pair<GLubyte, GLfloat*>(0x0b, BlockType::OakLog),
    std::pair<GLubyte, GLfloat*>(0x0c, BlockType::DarkOakLog),
    std::pair<GLubyte, GLfloat*>(0x0d, BlockType::SpruceLog),
    std::pair<GLubyte, GLfloat*>(0x0e, BlockType::BirchLog),
    std::pair<GLubyte, GLfloat*>(0x0f, BlockType::JungleLog),
    std::pair<GLubyte, GLfloat*>(0x10, BlockType::AcaciaLog),
    std::pair<GLubyte, GLfloat*>(0x11, BlockType::OakLeaves),
    std::pair<GLubyte, GLfloat*>(0x12, BlockType::DarkOakLeaves),
    std::pair<GLubyte, GLfloat*>(0x13, BlockType::SpruceLeaves),
    std::pair<GLubyte, GLfloat*>(0x14, BlockType::BirchLeaves),
    std::pair<GLubyte, GLfloat*>(0x15, BlockType::JungleLeaves),
    std::pair<GLubyte, GLfloat*>(0x16, BlockType::AcaciaLeaves),
    std::pair<GLubyte, GLfloat*>(0x17, BlockType::Water),
    std::pair<GLubyte, GLfloat*>(0x18, BlockType::Lava),
};

GLubyte BlockType::to_byte(GLfloat* type_vertices) {
    return byte_map.at(type_vertices);
}

GLfloat* BlockType::to_block_type(GLubyte type) {
    return block_type_map.at(type);
}

GLfloat BlockType::Grass[120] = {
    -0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,1.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,2.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,1.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,2.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,2.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,1.0f/8,8.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,2.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,2.0f/8,8.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,8.0f/8,
    -0.5f,-0.5f,-0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,8.0f/8
};

GLfloat BlockType::Dirt[120] = {
    -0.5f,-0.5f,-0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,0.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,1.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,8.0f/8,
     0.5f,-0.5f,-0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,8.0f/8,
     0.5f, 0.5f,-0.5f,0.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,0.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,8.0f/8,
    -0.5f,-0.5f,-0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,8.0f/8
};

GLfloat BlockType::Stone[120] = {
    -0.5f,-0.5f,-0.5f,0.0f/8,6.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,0.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,6.0f/8,
    -0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
    -0.5f, 0.5f,-0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,0.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,0.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,0.0f/8,6.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,0.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,0.0f/8,6.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,0.0f/8,7.0f/8
};

GLfloat BlockType::Sand[120] = {
    -0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,6.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,1.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,1.0f/8,6.0f/8,
    -0.5f,-0.5f,-0.5f,2.0f/8,6.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,1.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,2.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,2.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,2.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,2.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,1.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,6.0f/8,
     0.5f, 0.5f, 0.5f,2.0f/8,7.0f/8,
    -0.5f, 0.5f, 0.5f,1.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,1.0f/8,6.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,6.0f/8,
     0.5f,-0.5f, 0.5f,2.0f/8,7.0f/8,
    -0.5f,-0.5f, 0.5f,1.0f/8,7.0f/8
};

GLfloat BlockType::OakPlanks[120] = {
    -0.5f,-0.5f,-0.5f,2.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,2.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,1.0f/8
};

GLfloat BlockType::DarkOakPlanks[120] = {
    -0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8
};

GLfloat BlockType::SprucePlanks[120] = {
    -0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8
};

GLfloat BlockType::BirchPlanks[120] = {
    -0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8
};

GLfloat BlockType::JunglePlanks[120] = {
    -0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8
};

GLfloat BlockType::AcaciaPlanks[120] = {
    -0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,0.0f/8,
    -0.5f,-0.5f,-0.5f,8.0f/8,0.0f/8,
    -0.5f, 0.5f,-0.5f,8.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,0.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,1.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,0.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,0.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,1.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8
};

GLfloat BlockType::OakLog[120] = {
    -0.5f,-0.5f,-0.5f,2.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,2.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,3.0f/8
};

GLfloat BlockType::DarkOakLog[120] = {
    -0.5f,-0.5f,-0.5f,3.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8
};

GLfloat BlockType::SpruceLog[120] = {
    -0.5f,-0.5f,-0.5f,4.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8
};

GLfloat BlockType::BirchLog[120] = {
    -0.5f,-0.5f,-0.5f,5.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8
};

GLfloat BlockType::JungleLog[120] = {
    -0.5f,-0.5f,-0.5f,6.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8
};

GLfloat BlockType::AcaciaLog[120] = {
    -0.5f,-0.5f,-0.5f,7.0f/8,1.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,1.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8,
    -0.5f,-0.5f,-0.5f,8.0f/8,1.0f/8,
    -0.5f, 0.5f,-0.5f,8.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,2.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,2.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,1.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,1.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,2.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,2.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,3.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,2.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,2.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,3.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8
};

GLfloat BlockType::OakLeaves[120] = {
    -0.5f,-0.5f,-0.5f,2.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,2.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,2.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,2.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,2.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,2.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,3.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,2.0f/8,4.0f/8
};

GLfloat BlockType::DarkOakLeaves[120] = {
    -0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,3.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,3.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,3.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,4.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,3.0f/8,4.0f/8
};

GLfloat BlockType::SpruceLeaves[120] = {
    -0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,4.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,4.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,4.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,5.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,4.0f/8,4.0f/8
};

GLfloat BlockType::BirchLeaves[120] = {
    -0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,5.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,5.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,5.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,6.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,5.0f/8,4.0f/8
};

GLfloat BlockType::JungleLeaves[120] = {
    -0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,4.0f/8
};

GLfloat BlockType::AcaciaLeaves[120] = {
    -0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8,
    -0.5f,-0.5f,-0.5f,8.0f/8,3.0f/8,
    -0.5f, 0.5f,-0.5f,8.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,4.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,4.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,3.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,4.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,4.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,3.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,3.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,4.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,4.0f/8
};

GLfloat BlockType::Water[120] = {
    -0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,8.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,8.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,8.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,8.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,8.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,8.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,8.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,7.0f/8,8.0f/8
};

GLfloat BlockType::Lava[120] = {
    -0.5f,-0.5f,-0.5f,6.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,7.0f/8,
    -0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
    -0.5f, 0.5f,-0.5f,7.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,8.0f/8,
     0.5f,-0.5f,-0.5f,6.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
     0.5f, 0.5f,-0.5f,6.0f/8,8.0f/8,
    -0.5f, 0.5f,-0.5f,6.0f/8,7.0f/8,
     0.5f, 0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f, 0.5f, 0.5f,7.0f/8,8.0f/8,
    -0.5f, 0.5f, 0.5f,6.0f/8,8.0f/8,
    -0.5f,-0.5f,-0.5f,6.0f/8,7.0f/8,
     0.5f,-0.5f,-0.5f,7.0f/8,7.0f/8,
     0.5f,-0.5f, 0.5f,7.0f/8,8.0f/8,
    -0.5f,-0.5f, 0.5f,6.0f/8,8.0f/8
};
