//
// Created by 董宸 on 19/01/2018.
//

#ifndef LEARNINGOPENGL_GAMEOBJECTSYSTEM_HPP
#define LEARNINGOPENGL_GAMEOBJECTSYSTEM_HPP

#include <Entities/Entity.hpp>
#include "Systems/System.hpp"
namespace ReEngine{
    class GameObjectSystem : public System {

    public:

        auto CreateGameObject() -> EntityPtr;

        bool Init() override;

        void Update() override;

        void Uninit() override;
    };
}



#endif //LEARNINGOPENGL_GAMEOBJECTSYSTEM_HPP
