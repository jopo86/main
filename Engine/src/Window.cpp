#include "Window.hpp"

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) ErrorHandler::ERR(1, GL_TRUE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) ErrorHandler::ERR(2, GL_TRUE);
    make_current();

    glfwSetWindowUserPointer(window, this);
    glfwGetFramebufferSize(window, &buf_width, &buf_height);
    glfwSetWindowSizeCallback(window, CB_RESIZE);
    vidmode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) ErrorHandler::ERR(3, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, buf_width, buf_height);
}

void Window::swap_buffers() {
    glfwSwapBuffers(window);
}

void Window::make_current() {
    glfwMakeContextCurrent(window);
}

void Window::fullscreen() {
    glfwSetWindowSize(window, vidmode->width, vidmode->height);
    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, vidmode->width, vidmode->height, vidmode->refreshRate);
}

void Window::windowed() {
    glfwSetWindowSize(window, width, height);
    glfwSetWindowMonitor(window, nullptr, 0, 0, width, height, 0);
}

void Window::windowed_fullscreen() {
    glfwSetWindowSize(window, vidmode->width, vidmode->height);
    glfwSetWindowMonitor(window, nullptr, 0, 0, vidmode->width, vidmode->height, vidmode->refreshRate);
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

void Window::CB_RESIZE(GLFWwindow* window, int width, int height) {
    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    w->width = width;
    w->height = height;

    glfwGetFramebufferSize(window, &w->buf_width, &w->buf_height);
    glViewport(0, 0, w->buf_width, w->buf_height);
}
