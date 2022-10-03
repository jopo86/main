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

    double get_mouse_x();
    double get_mouse_y();

    bool check_key(GLenum key);

private:
    GLFWwindow* window;
    GLFWvidmode* vidmode;
    int width, height, buf_width, buf_height;

    bool keys[1024] = { 0 };

    double mouse_x;
    double mouse_y;

    static void CB_RESIZE(GLFWwindow* window, int width, int height);
    static void CB_KEY(GLFWwindow* window, int key, int code, int action, int mode);
    static void CB_MOUSE(GLFWwindow* window, double x, double y);

    void kb_inp_handle();
};