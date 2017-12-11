//
// Created by 董宸 on 11/12/2017.
//

#ifndef RENGINE_IMANAGER_H
#define RENGINE_IMANAGER_H

namespace Core{

    class IManager {

    public:
        virtual void Init() = 0;
        virtual void Update(float delayTime) = 0;
        virtual void UnInit() = 0;
    };

}



#endif //RENGINE_IMANAGER_H
