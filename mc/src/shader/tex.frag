#version 330

in vec2 tex_coord;

out vec4 color;

uniform sampler2D tex;

void main() {
    color = texture(tex, tex_coord);
}
