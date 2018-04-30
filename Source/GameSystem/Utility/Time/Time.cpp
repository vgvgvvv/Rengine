//
// Created by 董宸 on 07/01/2018.
//

#include <sys/time.h>
#include "Time.hpp"

namespace ReEngine{
    long Time::GetDelayTime() {
        return 15 * 1000;
    }

    long Time::GetCurrentTime() {
        long lLastTime = 0;
        struct timeval stCurrentTime;

        gettimeofday(&stCurrentTime, NULL);
        lLastTime = stCurrentTime.tv_sec*1000+stCurrentTime.tv_usec*0.001; // milliseconds
        return lLastTime;
    }
}