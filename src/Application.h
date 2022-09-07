#pragma once

#include <vector>

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Tex2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Application {
public:
    Application();

    void init();
    void run();
    void mainloop();

    void clear();
    ~Application();

private:
    const unsigned short SCR_WIDTH, SCR_HEIGHT;
    const char* TITLE;
    Window* window;
    std::vector<Mesh*> meshes;
    std::vector<Shader*> shaders;
    std::vector<Tex2D*> textures;
};
