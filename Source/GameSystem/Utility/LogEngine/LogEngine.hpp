//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_LOGENGINE_HPP
#define LEARNINGOPENGL_LOGENGINE_HPP


#include <Utility/Singleton.hpp>
#include <string>

namespace ReEngine{
    class LogEngine : public Singleton<LogEngine>{
    public:
        void log(std::string msg);
        void logWarning(std::string msg);
        void logError(std::string msg);
    };
}



#endif //LEARNINGOPENGL_LOGENGINE_HPP
