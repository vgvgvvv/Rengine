//
// Created by 董宸 on 11/12/2017.
//

#ifndef RENGINE_BASECOMPONENT_H
#define RENGINE_BASECOMPONENT_H


namespace Core{
    class IComponent {
    public:
        virtual void Init() = 0;
        virtual void Update(float delayTime) = 0;
        virtual void UnInit() = 0;
    };
}




#endif //RENGINE_BASECOMPONENT_H
