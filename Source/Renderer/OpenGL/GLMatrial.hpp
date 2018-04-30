//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_GLMATRIAL_HPP
#define LEARNINGOPENGL_GLMATRIAL_HPP

#include <vector>
#include "GLShader.hpp"
#include "GLTexture.hpp"

namespace ReOpenGL{
    //TODO 封装Matrial！！！
    class GLMatrial {
    public:

    private:
        std::vector<GLTexture> textures;
        GLShader shader;
    };
}


#endif //LEARNINGOPENGL_GLMATRIAL_HPP
