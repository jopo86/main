#pragma once

#include <glad/glad.h>

class Mesh {
public:
    Mesh(GLfloat* vertices, GLubyte* indices, GLsizei v_count, GLsizei i_count);

    void render();
    
    ~Mesh();

private:
    GLuint vao, vbo, ibo;
    GLsizei i_count;
};