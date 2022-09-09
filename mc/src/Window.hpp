#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);

    void init();
    void swap_buffers();
    void make_current();
    void fullscreen();
    void fullscreen_borderless();
    void windowed();

    bool should_close();

    int get_buf_width();
    int get_buf_height();

    double get_mouse_x();
    double get_mouse_y();

    ~Window();

private:
    GLFWwindow* window;
    GLFWvidmode* vidmode;
    int width, height, buf_width, buf_height;
    const char* title;

    bool keys[1024] = { 0 };

    double mouse_x;
    double mouse_y;

    GLbyte render_mode = 0x0;

    static void callback_window_size(GLFWwindow* window, int width, int height);
    static void callback_key(GLFWwindow* window, int key, int code, int action, int mode);
    static void callback_cursor_pos(GLFWwindow* window, double x, double y);

    void handle_keys();
};