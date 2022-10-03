#include "Application.hpp"

Application::Application() : INIT_WIDTH(1280), INIT_HEIGHT(720), TITLE("3D Engine") {}

void Application::init() {
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };

    GLuint indices[] = {
        0, 1, 2
    };

    window = new Window(INIT_WIDTH, INIT_HEIGHT, TITLE);
    triangle = new Mesh(vertices, indices, sizeof(vertices) / sizeof(GLfloat), sizeof(indices) / sizeof(GLuint));
}

void Application::run() {
    while (!window->should_close()) {
        mainloop();
    }
}

void Application::mainloop() {
    glfwPollEvents();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    triangle->render();

    window->swap_buffers();
}