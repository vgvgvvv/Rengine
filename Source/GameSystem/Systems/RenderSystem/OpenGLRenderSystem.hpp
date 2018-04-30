//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_OPENGLRENDERSYSTEM_HPP
#define LEARNINGOPENGL_OPENGLRENDERSYSTEM_HPP

#include "RenderSystem.hpp"
#include "OpenGL/OpenGLAllInOne.hpp"

using namespace ReOpenGL;

namespace ReEngine{
    class OpenGLRenderSystem : public RenderSystem{
    public:
        bool Init() override;

        void Update() override;

        void Uninit() override;

        bool GetShouldCloseWindow() override;

    private:
        GLWindow* window;
    };
}


#endif //LEARNINGOPENGL_OPENGLRENDERSYSTEM_HPP
