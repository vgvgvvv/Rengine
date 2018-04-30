//
// Created by 董宸 on 07/01/2018.
//
/**
 * 游戏世界的根，ECS架构中的世界
 */
#ifndef LEARNINGOPENGL_WORLD_HPP
#define LEARNINGOPENGL_WORLD_HPP

#include <vector>
#include <Utility/Singleton.hpp>
#include "Systems/System.hpp"
#include "Entities/Entity.hpp"
#include "Systems/RenderSystem/RenderSystem.hpp"
#include "Systems/GameObjectSystem/EntitySystem.hpp"

namespace ReEngine{
    class World : public Singleton<World>{
    public:
        World();
        ~World();
        bool Init();
        void Run();
        void Update();
        void Uninit();
        bool ShouldQuit();
    private:
        std::vector<System*> systemVector;

    private:
        GameObjectSystem* gameObjectSystem;
        RenderSystem* renderSystem;
    };
}



#endif //LEARNINGOPENGL_WORLD_HPP
