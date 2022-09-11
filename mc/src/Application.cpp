#include "Application.hpp"

Application::Application() : SCR_WIDTH(1280), SCR_HEIGHT(720), TITLE("Minecraft Clone") {}

void Application::init() {
    window = Window(SCR_WIDTH, SCR_HEIGHT, TITLE);
    window.init();
    window.fullscreen();
    
    chunk = Chunk(glm::vec3(0, 0, 0));
    
    camera = Camera(glm::vec3(0, 0, 0), 0, 0, 15, 20);

    shader = Shader("src/shader/tex.vert", "src/shader/tex.frag");
    tex_atlas = Tex2D("assets/textures/atlas.png");
}

void Application::run() {
    tex_atlas.bind();
    shader.bind();
    while (!window.should_close()) {
        mainloop();
    }

    glfwTerminate();
}

void Application::mainloop() {
    glfwPollEvents();

    glClearColor(0.3, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.key_control(window.get_keys());
    camera.mouse_control(window.get_mouse_x(), window.get_mouse_y());

    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(0, 0, 0));
    //model = glm::rotate(model, glm::radians(rotation), glm::vec3(1, 0, 0));

    glm::mat4 projection = glm::perspective(45.0f, (float)window.get_buf_width() / (float)window.get_buf_height(), 0.1f, 1000.0f);

    shader.uniform_mat4("model", glm::value_ptr(model));
    shader.uniform_mat4("view", glm::value_ptr(camera.get_view_matrix()));
    shader.uniform_mat4("projection", glm::value_ptr(projection));
    chunk.render();
    
    window.swap_buffers();
}

Application::~Application() {}
