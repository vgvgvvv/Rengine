//
// Created by 董宸 on 19/01/2018.
//

#include "EntitySystem.hpp"
#include "Entities/EntityPool.hpp"

namespace ReEngine{

    bool GameObjectSystem::Init() {
        return true;
    }

    void GameObjectSystem::Update() {

    }

    void GameObjectSystem::Uninit() {

    }

    auto GameObjectSystem::CreateGameObject() -> EntityPtr {
        return EntityPool::GetObject();
    }
}