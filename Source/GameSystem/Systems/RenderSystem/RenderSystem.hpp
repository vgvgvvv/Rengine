//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_RENDERSYSTEM_HPP
#define LEARNINGOPENGL_RENDERSYSTEM_HPP

#include "Systems/System.hpp"

namespace ReEngine{
    class RenderSystem : public System {
    public:
        virtual bool GetShouldCloseWindow() = 0;
    };
}


#endif //LEARNINGOPENGL_RENDERSYSTEM_HPP
