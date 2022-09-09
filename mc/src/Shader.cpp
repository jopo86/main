#include "Shader.hpp"

Shader::Shader(const char* v_path, const char* f_path) : program(0) {
    vs = read_file(v_path).c_str();
    fs = read_file(f_path).c_str();
    compile();
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

void Shader::compile() {
    program = glCreateProgram();
    add(vs, GL_VERTEX_SHADER);
    add(fs, GL_FRAGMENT_SHADER);

    glLinkProgram(program);

    GLint status = 0;
    glValidateProgram(program);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (!status) {
        printf("failed to validate\n");
        GLchar log[1024] = { 0 };
        glGetProgramInfoLog(program, 1024, nullptr, log);
        printf("%s\n", log);
    }
}

void Shader::add(const char* code, GLenum type) {
    const char* type_str = type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader";
    GLuint shader = glCreateShader(type);

    const GLchar* string[] = { code };
    GLint length[] = { (GLint)strlen(code) };

    glShaderSource(shader, 1, string, length);

    GLint status = 0;
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        printf("failed to compile %s\n", type_str);
        GLchar log[1024] = { 0 };
        glGetShaderInfoLog(shader, 1024, nullptr, log);
        printf("%s\n", log);
    }

    glAttachShader(program, shader);
}

std::string Shader::read_file(const char* path) {
    std::string line;
    std::string content;
    std::fstream file(path, std::ios::in);

    if (!file.is_open()) {
        printf("Failed to locate \"%s\"", path);
        return "";
    }

    while (!file.eof()) {
        std::getline(file, line);
        content.append(line + "\n");
    }

    return content;
}

Shader::~Shader() {}
