#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;

uniform mat4 model;
uniform mat4 projection;

out vec2 tex_coord;

void main() {
    gl_Position = projection * model * vec4(pos, 1.0f);
    tex_coord = uv;
}
