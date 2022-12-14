#pragma once

#include <iostream>

#include <glad/glad.h>

class Tex2D {
public:
    Tex2D(){}
    Tex2D(const char* img_path);

    void bind();
    void unbind();

    ~Tex2D();

private:
    GLuint tex;
    int tex_width;
    int tex_height;
    int comp;
};