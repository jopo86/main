#include "ErrorHandler.hpp"

std::map<int, const char*> ErrorHandler::err_list = {
    std::pair<int, const char*>(1, "ERR_001: failed to initialize GLFW"),
    std::pair<int, const char*>(2, "ERR_002: failed to create window"),
    std::pair<int, const char*>(3, "ERR_003: failed to initialize graphics API"),
    std::pair<int, const char*>(4, "ERR_004: failed to locate or open file"),
};

void ErrorHandler::ERR(int code, int8_t terminate) {
    printf("%s\n", err_list[code]);
    if (terminate) {
        glfwTerminate();
        exit(code);
    }
}

void ErrorHandler::ERR_PARAM(int code, const char* param, int8_t terminate) {
    printf("%s (%s)\n", err_list[code], param);
    if (terminate) {
        glfwTerminate();
        exit(code);
    }
}

int ErrorHandler::get_err_code(const char* str) {
    for (int i = 0; i < err_list.size(); i++) {
        if (str == err_list[i]) return i;
    }
    return -1;
}