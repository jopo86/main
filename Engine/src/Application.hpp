#pragma once

#include "Window.hpp"

class Application {
public:
    Application();

    void init();
    void run();

private:
    void mainloop();

    const int INIT_WIDTH, INIT_HEIGHT;
    const char* TITLE;

    Window* window;

};