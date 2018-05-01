//
// Created by ¶­å· on 2018/5/1.
//

#include <Application.hpp>
#include <iostream>

int main(int argc, char **argv){

    std::cout << ReEngine::Application::GetInstance().GetProjectPath() << std::endl;
    return 0;
}