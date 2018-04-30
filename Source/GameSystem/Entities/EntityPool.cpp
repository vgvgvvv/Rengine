//
// Created by 董宸 on 18/01/2018.
//

#include "EntityPool.hpp"

namespace ReEngine{
    EntityPtr EntityPool::GetObject() {
        //TODO 暂时使用New 后面再使用池子
        auto newObj = new Entity;
        return newObj;
    }

}