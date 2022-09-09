#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <glad/glad.h>

class Shader {
public:
    Shader(const char* v_path, const char* f_path);

    void bind();
    void unbind();

    void uniform_mat4(const char* name, const GLfloat* val);
    void uniform_vec3(const char* name, const GLfloat* val);
    void uniform_float(const char* name, const GLfloat val);

    ~Shader();

private:
    GLuint program;
    const char* vs;
    const char* fs;

    void compile();
    void add(const char* code, GLenum type);
    std::string read_file(const char* path);
};