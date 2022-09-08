#include "Window.hpp"

Window::Window(int width, int height, const char* title) : buf_width(0), buf_height(0), window(0), vidmode(0), mouse_x(0), mouse_y(0) {
    this->width = width;
    this->height = height;
    this->title = title;
}

void Window::init() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        glfwTerminate();
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title, 0, 0);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        exit(-1);
    }

    make_current();

    vidmode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwGetFramebufferSize(window, &buf_width, &buf_height);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPos(window, (double)buf_width / 2, (double)buf_height / 2);

    glfwSetWindowSizeCallback(window, callback_window_size);
    glfwSetKeyCallback(window, callback_key);
    glfwSetCursorPosCallback(window, callback_cursor_pos);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(-1);
    }

    glViewport(0, 0, buf_width, buf_height);
    glEnable(GL_DEPTH_TEST);
}

void Window::swap_buffers() {
    glfwSwapBuffers(window);
}

void Window::make_current() {
    glfwMakeContextCurrent(window);
}

void Window::fullscreen() {
    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, vidmode->width, vidmode->height, vidmode->refreshRate);
}

void Window::fullscreen_borderless() {
    glfwSetWindowMonitor(window, 0, 0, 0, vidmode->width, vidmode->height, vidmode->refreshRate);
}

void Window::windowed() {
    glfwSetWindowMonitor(window, 0, 0, 0, width, height, 0);
}

bool Window::should_close() {
    return glfwWindowShouldClose(window);
}

int Window::get_buf_width() {
    return buf_width;
}

int Window::get_buf_height() {
    return buf_height;
}

double Window::get_mouse_x() {
    return mouse_x;
}

double Window::get_mouse_y() {
    return mouse_y;
}


void Window::callback_window_size(GLFWwindow* window, int width, int height) {
    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    glfwGetFramebufferSize(window, &w->buf_width, &w->buf_height);
    glViewport(0, 0, w->buf_width, w->buf_height);
}

void Window::callback_key(GLFWwindow* window, int key, int code, int action, int mode) {
    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (action == GLFW_PRESS || action == GLFW_REPEAT) w->keys[key] = true;
    else if (action == GLFW_RELEASE) w->keys[key] = false;

    w->handle_keys();
}

void Window::callback_cursor_pos(GLFWwindow* window, double x, double y) {
    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    w->mouse_x = x;
    w->mouse_y = y;
}

void Window::handle_keys() {
    if (keys[GLFW_KEY_ESCAPE]) glfwSetWindowShouldClose(window, GL_TRUE);
    if (keys[GLFW_KEY_LEFT_ALT]) {
        render_mode = ~render_mode;
        glPolygonMode(GL_FRONT_AND_BACK, render_mode == 0x0 ? GL_FILL : GL_LINE);
    }
}

void Window::clear() {
    if (window) glfwDestroyWindow(window);
    window = 0;
    vidmode = 0;
    width = height = buf_width = buf_height = 0;
    title = 0;
    for (int i = 0; i < 1024; i++) keys[i] = 0;
    mouse_x = mouse_y = 0;
    render_mode = 0;
}

Window::~Window() {
    clear();
}
