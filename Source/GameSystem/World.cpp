//
// Created by 董宸 on 07/01/2018.
//

#include <thread>
#include <Systems/RenderSystem/RenderSystem.hpp>
#include "Utility/Utility.hpp"
#include "World.hpp"
#include "Systems/RenderSystem/OpenGLRenderSystem.hpp"

namespace ReEngine{

    World::World() {
        gameObjectSystem = new GameObjectSystem();
        systemVector.push_back(gameObjectSystem);
        renderSystem = new OpenGLRenderSystem();
        systemVector.push_back(renderSystem);
    }

    World::~World() {
        delete renderSystem;
        delete gameObjectSystem;
    }

    bool World::Init() {

        for(auto system : systemVector){
            if(!system->Init()){
                return false;
            }
        }
        return true;
    }

    void World::Run() {
        if(!this->Init()){
            LogEngine::GetInstance().logError("Init Fail!!!");
            assert(false);
            return;
        }

        long lastTime = 0L;
        long curTime = 0L;

        while(!ShouldQuit()){
            lastTime = Time::GetCurrentTime();

            //逻辑部分更新
            this->Update();

            curTime = Time::GetCurrentTime();
            if (curTime - lastTime < Time::GetDelayTime())
            {
                std::this_thread::sleep_for(std::chrono::nanoseconds((Time::GetDelayTime() - curTime + lastTime) * 1000));
            }
        }
        this->Uninit();
        LogEngine::GetInstance().log("Uninit");
    }

    void World::Update() {
        if(systemVector.size() == 0)
            return;
        for(auto system : systemVector){
            system->Update();
        }
    }

    void World::Uninit() {
        for(auto system : systemVector){
            system->Uninit();
        }
    }

    bool World::ShouldQuit() {
        return false;
    }

}