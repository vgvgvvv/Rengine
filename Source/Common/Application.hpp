//
// Created by 董宸 on 2018/5/1.
//

#ifndef RENGINE_APPLICATION_HPP
#define RENGINE_APPLICATION_HPP

#include <Utility/Singleton.hpp>
#include <string>

namespace ReEngine{
    class Application {

    public:

        Application() = default;

        /**
         * 获取当前工程文件夹
         * @return
         */
        static std::string GetProjectPath();


    private:
        static std::string projectPath;
    };
}


#endif //RENGINE_APPLICATION_HPP
