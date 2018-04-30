//
// Created by 董宸 on 07/01/2018.
//

#include "LogEngine.hpp"
#include <iostream>

namespace ReEngine{
    void LogEngine::log(std::string msg) {
        std::cout << __FILE__<< ":" <<__LINE__ << "Log:" << msg << std::endl;
    }

    void LogEngine::logWarning(std::string msg) {
        std::clog << __FILE__<< ":" <<__LINE__ << "Warning:" << msg << std::endl;
    }

    void LogEngine::logError(std::string msg) {
        std::cerr << __FILE__<< ":" <<__LINE__ << "Error:" << msg << std::endl;
    }
}