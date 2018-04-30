//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_TIME_HPP
#define LEARNINGOPENGL_TIME_HPP

#include <cstdint>

namespace ReEngine{
    class Time {
    public:
        /**
         * 获取每帧的间隔时间
         * @return
         */
        static long GetDelayTime();
        /**
         * 获取当前时间
         * @return
         */
        static long GetCurrentTime();
    };
}



#endif //LEARNINGOPENGL_TIME_HPP
