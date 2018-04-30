//
// Created by 董宸 on 07/01/2018.
//

/**
 * ECS中的S，包含所有逻辑运算
 */
#ifndef LEARNINGOPENGL_SYSTEM_HPP
#define LEARNINGOPENGL_SYSTEM_HPP

namespace ReEngine{
    class System {
    public:
        virtual bool Init() = 0;
        virtual void Update() = 0;
        virtual void Uninit() = 0;
    };
}


#endif //LEARNINGOPENGL_SYSTEM_HPP
