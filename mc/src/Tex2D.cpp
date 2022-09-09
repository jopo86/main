#include "Tex2D.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

Tex2D::Tex2D(const char* img_path) {
    stbi_set_flip_vertically_on_load(true);
    GLubyte* data = stbi_load(img_path, &tex_width, &tex_height, &comp, 0);
    if (!data) {
        printf("failed to load \"%s\" using STBI", img_path);
        return;
    }

    glGenTextures(1, &tex);
    bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    unbind();
}

void Tex2D::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
}

void Tex2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Tex2D::~Tex2D() {}
