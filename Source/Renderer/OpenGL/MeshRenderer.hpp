//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_MESHRENDERER_HPP
#define LEARNINGOPENGL_MESHRENDERER_HPP


#include "OpenGLAllInOne.hpp"

namespace ReOpenGL{
    //TODO 封装渲染器
    class MeshRenderer {
    public:
        void Render();
    private:
        GLMesh mesh;
        GLShader shader;
    };
}



#endif //LEARNINGOPENGL_MESHRENDERER_HPP
