//
// Created by 董宸 on 2018/4/15.
//

#include <bitset>
#include "Transform.hpp"

namespace ReEngine{


    std::size_t Transform::GetComponentTypeHash() const {
        return std::hash<std::string>{}("Transform");
    }

    void Transform::Awake() {

    }

    void Transform::Start() {

    }

    void Transform::Update() {

    }

    void Transform::OnDestroy() {

    }
}