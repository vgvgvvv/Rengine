//
// Created by ¶­å· on 2018/5/1.
//

#include <string>
#include <zconf.h>
#include <Utility/LogEngine/LogEngine.hpp>
#include "Application.hpp"

namespace ReEngine{

    std::string Application::GetProjectPath() {
        if(projectPath.empty()){
            char *path;
            path = getcwd(NULL, 0);
            if(path == nullptr){
                LogEngine::GetInstance().logError("get projectPath failed!");
            }
            projectPath = std::string(path);
            delete path;
        }
        return projectPath;
    }

}