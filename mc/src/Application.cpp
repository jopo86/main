#include "Application.hpp"

Application::Application() : SCR_WIDTH(1280), SCR_HEIGHT(720), TITLE("Minecraft Clone") {
    window = nullptr;
    tex_atlas = nullptr;
    shader = nullptr;
    rotation = 0;
}

void Application::init() {
    GLfloat vertices[] = {
        // X     Y      Z    |    U    V
        // front
        -1.0f, -1.0f,  0.0f,     1.0f/8, 7.0f/8,
         1.0f, -1.0f,  0.0f,     2.0f/8, 7.0f/8,
         1.0f,  1.0f,  0.0f,     2.0f/8, 8.0f/8,
        -1.0f,  1.0f,  0.0f,     1.0f/8, 8.0f/8,
        // left
        -1.0f, -1.0f, -2.0f,     1.0f/8, 7.0f/8,
        -1.0f, -1.0f,  0.0f,     2.0f/8, 7.0f/8,
        -1.0f,  1.0f,  0.0f,     2.0f/8, 8.0f/8,
        -1.0f,  1.0f, -2.0f,     1.0f/8, 8.0f/8,
        // back
        -1.0f, -1.0f, -2.0f,     1.0f/8, 7.0f/8,
         1.0f, -1.0f, -2.0f,     2.0f/8, 7.0f/8,
         1.0f,  1.0f, -2.0f,     2.0f/8, 8.0f/8,
        -1.0f,  1.0f, -2.0f,     1.0f/8, 8.0f/8,
        //right
         1.0f, -1.0f,  0.0f,     1.0f/8, 7.0f/8,
         1.0f, -1.0f, -2.0f,     2.0f/8, 7.0f/8,
         1.0f,  1.0f, -2.0f,     2.0f/8, 8.0f/8,
         1.0f,  1.0f,  0.0f,     1.0f/8, 8.0f/8,
        //top
        -1.0f,  1.0f,  0.0f,     2.0f/8, 7.0f/8,
         1.0f,  1.0f,  0.0f,     3.0f/8, 7.0f/8,
         1.0f,  1.0f, -2.0f,     3.0f/8, 8.0f/8,
        -1.0f,  1.0f, -2.0f,     2.0f/8, 8.0f/8,
        //bottom
        -1.0f, -1.0f,  0.0f,     0.0f/8, 7.0f/8,
         1.0f, -1.0f,  0.0f,     1.0f/8, 7.0f/8,
         1.0f, -1.0f, -2.0f,     1.0f/8, 8.0f/8,
        -1.0f, -1.0f, -2.0f,     0.0f/8, 8.0f/8,
    };

    GLubyte indices[] = {
        // front
        0x00, 0x01, 0x02,
        0x00, 0x03, 0x02,
        // left
        0x04, 0x05, 0x06,
        0x04, 0x07, 0x06,
        // back
        0x08, 0x09, 0x0a,
        0x08, 0x0b, 0x0a,
        // right
        0x0c, 0x0d, 0x0e,
        0x0c, 0x0f, 0x0e,
        // top
        0x10, 0x11, 0x12,
        0x10, 0x13, 0x12,
        //bottom
        0x14, 0x15, 0x16,
        0x14, 0x17, 0x16,
    };

    window = new Window(SCR_WIDTH, SCR_HEIGHT, TITLE);
    window->init();
    
    meshes.push_back(new Mesh(vertices, indices, sizeof(vertices) / sizeof(*vertices), sizeof(indices) / sizeof(*indices)));
    shader = new Shader("src/shader/tex.vert", "src/shader/tex.frag");
    tex_atlas = new Tex2D("assets/textures/atlas.png");
}

void Application::run() {
    shader->bind();
    tex_atlas->bind();
    while (!window->should_close()) {
        mainloop();
    }

    glfwTerminate();
}

void Application::mainloop() {
    glfwPollEvents();

    glClearColor(0.3, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    rotation += 0.5f;
    if (rotation >= 360.0f) rotation = 0.0f;

    glm::mat4 model(1.0f);
    model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
    model = glm::translate(model, glm::vec3(0, 0, -4));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.3, 1, 0.3));

    glm::mat4 view(1.0f);
    view = glm::translate(view, glm::vec3(0, 0, -2));

    glm::mat4 projection = glm::perspective(45.0f, (float)window->get_buf_width() / (float)window->get_buf_height(), 0.1f, 100.0f);

    shader->uniform_mat4("model", glm::value_ptr(model));
    shader->uniform_mat4("view", glm::value_ptr(view));
    shader->uniform_mat4("projection", glm::value_ptr(projection));
    meshes[0]->render();

    window->swap_buffers();
}

void Application::clear() {
    window = 0;
}

Application::~Application() {
    clear();
}
