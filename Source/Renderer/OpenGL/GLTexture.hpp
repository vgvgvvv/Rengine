//
// Created by 董宸 on 06/01/2018.
//

#ifndef LEARNINGOPENGL_GLTEXTURE_HPP
#define LEARNINGOPENGL_GLTEXTURE_HPP

#include "glew/glew.h"
#include "glfw/glfw3.h"
#include "stb/stb_image.h"

namespace ReOpenGL{

    enum WrapType{

    };

    class GLTexture {
    public:

        GLTexture(const char* texturePath);
        GLTexture(const std::string texturePath);

        ~GLTexture();

        void Use(GLenum type);

        void Build();

        void setNewTexture(const char* texturePath);

        GLuint getTexID() const;
        GLint getWidth() const;
        GLint getHeight() const;
        GLint getNrChannel() const;

        GLenum getWrapTypeS() const;
        void setWrapTypeS(GLenum wrapTypeS);
        GLenum getWrapTypeT() const;
        void setWrapTypeT(GLenum wrapTypeT);
        GLenum getMinFilter() const;
        void setMinFilter(GLenum minFilter);
        GLenum getMagFilter() const;
        void setMagFilter(GLenum magFilter);

    private:
        GLuint texID;
        GLint width;
        GLint height;
        GLint nrChannel;

        GLenum wrapTypeS;
        GLenum wrapTypeT;

        GLenum minFilter;
        GLenum magFilter;

        unsigned char *data;
        const char* texturePath;
    };
}

#endif //LEARNINGOPENGL_GLTEXTURE_HPP
