#pragma once

#include <glad/glad.h>

class Mesh {
public:
    Mesh(){}
    Mesh(GLfloat* vertices, GLuint* indices, GLsizei v_count, GLsizei i_count);

    void render();

private:
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    GLsizei i_count;
};