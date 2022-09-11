#include "Shader.hpp"

Shader::Shader(const char* v_path, const char* f_path) : program(0) {
    compile(read_file(v_path).c_str(), read_file(f_path).c_str());
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::uniform_mat4(const char* name, const GLfloat* val) {
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, val);
}

void Shader::uniform_vec3(const char* name, const GLfloat* val) {
    glUniform3fv(glGetUniformLocation(program, name), 1, val);
}

void Shader::uniform_float(const char* name, const GLfloat val) {
    glUniform1f(glGetUniformLocation(program, name), val);
}

void Shader::compile(const char* v, const char* f) {
    program = glCreateProgram();
    add(v, GL_VERTEX_SHADER);
    add(f, GL_FRAGMENT_SHADER);

    GLint status = 0;

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (!status) {
        printf("ERROR failed to link shader program\n");
        GLchar log[1024] = { 0 };
        glGetProgramInfoLog(program, 1024, nullptr, log);
        printf("%s\n", log);
    }

    glValidateProgram(program);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (!status) {
        printf("ERROR failed to validate shader program\n");
        GLchar log[1024] = { 0 };
        glGetProgramInfoLog(program, 1024, nullptr, log);
        printf("%s\n", log);
    }
}

void Shader::add(const char* code, GLenum type) {
    const char* type_str = type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader";
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &code, NULL);

    GLint status = 0;
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        printf("ERROR: failed to compile %s\n", type_str);
        GLchar log[1024] = { 0 };
        glGetShaderInfoLog(shader, 1024, nullptr, log);
        printf("%s\n", log);
    }

    glAttachShader(program, shader);
    glDeleteShader(shader);
}

std::string Shader::read_file(const char* path) {
    std::string content;
    std::string line;
    std::fstream file(path, std::ios::in);

    if (!file.is_open()) {
        printf("ERROR: failed to locate \"%s\"", path);
        return "";
    }

    while (!file.eof()) {
        std::getline(file, line);
        content.append(line + "\n");
    }

    file.close();
    return content;
}

Shader::~Shader() {}
