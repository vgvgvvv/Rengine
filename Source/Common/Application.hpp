//
// Created by 董宸 on 2018/5/1.
//

#ifndef RENGINE_APPLICATION_HPP
#define RENGINE_APPLICATION_HPP

#include <Utility/Singleton.hpp>

namespace ReEngine{
    class Application : Singleton<Application>{

    public:

        Application() = default;

        /**
         * 获取当前工程文件夹
         * @return
         */
        std::string GetProjectPath();

        /**
         * 获取资源文件夹
         * @return
         */
        std::string GetResourcesPath();

    private:
        std::string projectPath;
        std::string resourcesPath;
    };
}


#endif //RENGINE_APPLICATION_HPP
