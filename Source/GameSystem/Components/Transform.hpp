//
// Created by 董宸 on 2018/4/15.
//

#ifndef LEARNINGOPENGL_TRANSFORM_HPP
#define LEARNINGOPENGL_TRANSFORM_HPP


#include <glm/vec3.hpp>
#include "Component.hpp"

namespace ReEngine{
    class Transform : public Component{
    public:
        Transform* parent;
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 eulerAngle;

        std::size_t GetComponentTypeHash() const override;

        void Awake() override;

        void Start() override;

        void Update() override;

        void OnDestroy() override;
    };

}


#endif //LEARNINGOPENGL_TRANSFORM_HPP
