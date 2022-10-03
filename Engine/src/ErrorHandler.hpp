#pragma once

#include <GLFW/glfw3.h>

#include <map>

class ErrorHandler {
public:
    static void ERR(int code, int8_t terminate);
    static void ERR_PARAM(int code, const char* param, int8_t terminate);
    static int get_err_code(const char* str);
    
    static std::map<int, const char*> err_list;
};