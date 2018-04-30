//
// Created by 董宸 on 07/01/2018.
//

#include "Entity.hpp"


namespace ReEngine{

    //TODO 实现Component工具函数
    EntityPtr Entity::AddComponent(Component* component) {
        this->components.push_back(component);
        return this;
    }

    EntityPtr Entity::RemoveComponent(const std::string name){
        auto hash = std::hash<std::string>{}(name);
        for(std::size_t i = 0; i < components.size(); i ++){
            if(components.at(i)->GetComponentTypeHash() == hash){
                components.erase(components.begin()+i);
                break;
            }
        }
        return this;
    }

    bool Entity::HasComponent(const std::string name) {
        auto hash = std::hash<std::string>{}(name);
        for(std::size_t i = 0; i < components.size(); i ++){
            if(components.at(i)->GetComponentTypeHash() == hash){
                return true;
            }
        }
        return false;
    }

    void Entity::Awake() {
        for(auto &component : components){
            component->Awake();
        }
    }

    void Entity::Start() {
        for(auto &component : components){
            component->Start();
        }
    }

    void Entity::Update() {
        for(auto &component : components){
            component->Update();
        }
    }

    void Entity::OnDestroy() {
        for(auto &component : components){
            component->OnDestroy();
        }
    }
}