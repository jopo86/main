#pragma once

#include <vector>

#include "Window.hpp"
#include "Block.hpp"
#include "BlockType.hpp"
#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Application {
public:
    Application();

    void init();
    void run();
    void mainloop();

    ~Application();

private:
    const unsigned short SCR_WIDTH, SCR_HEIGHT;
    const char* TITLE;
    Window* window;
    std::vector<Block*> blocks;
    Tex2D* tex_atlas;
    Shader* shader;

    float rotation;
};
