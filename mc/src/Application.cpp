#include "Application.hpp"

Application::Application() : SCR_WIDTH(1280), SCR_HEIGHT(720), TITLE("Minecraft Clone") {
    window = nullptr;
    tex_atlas = nullptr;
    shader = nullptr;
    blocks = {};
    rotation = 0;
}

void Application::init() {
    

    window = new Window(SCR_WIDTH, SCR_HEIGHT, TITLE);
    window->init();
    
    blocks.push_back(new Block(BlockType::Grass,     glm::vec3(-4.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::Dirt,      glm::vec3(-3.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::Stone,     glm::vec3(-2.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::Sand,      glm::vec3(-1.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::OakPlanks,  glm::vec3(0.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::OakLog,     glm::vec3(1.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::OakLeaves,  glm::vec3(2.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::Water,      glm::vec3(3.0f, 0.0f, 0.0f)));
    blocks.push_back(new Block(BlockType::Lava,       glm::vec3(4.0f, 0.0f, 0.0f)));
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
    model = glm::translate(model, glm::vec3(0, 0, 0));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(1, 0, 0));

    glm::mat4 view(1.0f);
    view = glm::translate(view, glm::vec3(0, 0, -10));

    glm::mat4 projection = glm::perspective(45.0f, (float)window->get_buf_width() / (float)window->get_buf_height(), 0.1f, 100.0f);

    shader->uniform_mat4("model", glm::value_ptr(model));
    shader->uniform_mat4("view", glm::value_ptr(view));
    shader->uniform_mat4("projection", glm::value_ptr(projection));
    blocks[0]->render();
    blocks[1]->render();
    blocks[2]->render();
    blocks[3]->render();
    blocks[4]->render();
    blocks[5]->render();
    blocks[6]->render();
    blocks[7]->render();
    blocks[8]->render();

    window->swap_buffers();
}

Application::~Application() {}
