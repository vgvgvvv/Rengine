//
// Created by 董宸 on 06/01/2018.
//

#include <iostream>
#include <string>
#include "GLTexture.hpp"

namespace ReOpenGL{

    GLTexture::GLTexture(const char *texturePath) :
        texID(0),
        width(800),
        height(600),
        nrChannel(0),
        wrapTypeS(GL_REPEAT),
        wrapTypeT(GL_REPEAT),
        minFilter(GL_LINEAR),
        magFilter(GL_LINEAR),
        data(nullptr)
    {
        this->texturePath = texturePath;
    }

    GLTexture::GLTexture(const std::string texturePath) :
            texID(0),
            width(800),
            height(600),
            nrChannel(0),
            wrapTypeS(GL_REPEAT),
            wrapTypeT(GL_REPEAT),
            minFilter(GL_LINEAR),
            magFilter(GL_LINEAR),
            data(nullptr)
    {
        this->texturePath = texturePath.c_str();
    }

    GLTexture::~GLTexture() {

    }

    void GLTexture::Use(GLenum type) {
        glActiveTexture(type);
        glBindTexture(GL_TEXTURE_2D, texID);
    }

    void GLTexture::Build() {
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_2D, texID);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapTypeS);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapTypeT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(texturePath, &width, &height, &nrChannel, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
        data = nullptr;
    }

    void GLTexture::setNewTexture(const char* texturePath){

        if(this->data != nullptr){
            stbi_image_free(data);
        }
        this->texturePath = texturePath;
    }

    GLuint GLTexture::getTexID() const {
        return texID;
    }

    GLint GLTexture::getWidth() const {
        return width;
    }

    GLint GLTexture::getHeight() const {
        return height;
    }

    GLint GLTexture::getNrChannel() const {
        return nrChannel;
    }

    GLenum GLTexture::getWrapTypeS() const {
        return wrapTypeS;
    }

    void GLTexture::setWrapTypeS(GLenum wrapTypeS) {
        GLTexture::wrapTypeS = wrapTypeS;
    }

    GLenum GLTexture::getWrapTypeT() const {
        return wrapTypeT;
    }

    void GLTexture::setWrapTypeT(GLenum wrapTypeT) {
        GLTexture::wrapTypeT = wrapTypeT;
    }

    GLenum GLTexture::getMinFilter() const {
        return minFilter;
    }

    void GLTexture::setMinFilter(GLenum minFilter) {
        GLTexture::minFilter = minFilter;
    }

    GLenum GLTexture::getMagFilter() const {
        return magFilter;
    }

    void GLTexture::setMagFilter(GLenum magFilter) {
        GLTexture::magFilter = magFilter;
    }

}
