//
// Created by 董宸 on 07/01/2018.
//

/**
 * ECS中的C，游戏实体上的组件
 */
#ifndef LEARNINGOPENGL_COMPONENT_HPP
#define LEARNINGOPENGL_COMPONENT_HPP

#include <cstddef>

namespace ReEngine{
    class Component {
    public:
        /**
         * Component种类的唯一标示符
         * @return
         */
        virtual std::size_t GetComponentTypeHash() const = 0;
        virtual void Awake() = 0 ;
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void OnDestroy() = 0;
    };

}


#endif //LEARNINGOPENGL_COMPONENT_HPP
