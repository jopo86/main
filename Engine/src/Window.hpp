#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "ErrorHandler.hpp"

class Window {
public:
    Window(){}
    Window(int width, int height, const char* title);

    void swap_buffers();
    void make_current();
    void fullscreen();
    void windowed();
    void windowed_fullscreen();
    bool should_close();

    int get_buf_width();
    int get_buf_height();

private:
    GLFWwindow* window;
    GLFWvidmode* vidmode;
    int width, height, buf_width, buf_height;

    static void CB_RESIZE(GLFWwindow* window, int width, int height);
};