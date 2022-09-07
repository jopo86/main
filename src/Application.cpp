#include "Application.hpp"

Application::Application() : SCR_WIDTH(1280), SCR_HEIGHT(720), TITLE("Minecraft Clone") {
    window = nullptr;
}

void Application::init() {
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,     0, 0,
         1.0f, -1.0f, 0.0f,     1, 0,
         1.0f,  1.0f, 0.0f,     1, 1,
        -1.0f,  1.0f, 0.0f,     0, 1,
    };

    GLubyte indices[] = {
        0x00, 0x01, 0x02,
        0x00, 0x03, 0x02,
    };

    window = new Window(SCR_WIDTH, SCR_HEIGHT, TITLE);
    window->init();
    
    meshes.push_back(new Mesh(vertices, indices, sizeof(vertices) / sizeof(*vertices), sizeof(indices) / sizeof(*indices)));
    shaders.push_back(new Shader("src/shader/tex.vert", "src/shader/tex.frag"));
    textures.push_back(new Tex2D("assets/textures/grass_side.png"));
}

void Application::run() {
    while (!window->should_close()) {
        mainloop();
    }

    glfwTerminate();
}

void Application::mainloop() {
    glfwPollEvents();

    glClearColor(0.3, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 model(1.0f);
    model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
    model = glm::translate(model, glm::vec3(0, 0, -4));

    glm::mat4 projection = glm::perspective(45.0f, (float)window->get_buf_width() / (float)window->get_buf_height(), 0.1f, 100.0f);

    textures[0]->bind();
    shaders[0]->uniform_mat4("projection", glm::value_ptr(projection));
    shaders[0]->uniform_mat4("model", glm::value_ptr(model));
    shaders[0]->bind();
    meshes[0]->render();

    window->swap_buffers();
}

void Application::clear() {
    window = 0;
}

Application::~Application() {
    clear();
}
