#include <string>
#include <iostream>
#include <fstream>
#include "FileOperation.hpp"


/**
 * 读取文件
 * @param path
 * @param result
 */
bool ReadFile(const char* path, std::string &result){

    result = "";

    std::ifstream shaderStream(path, std::ios::in);
    if(shaderStream.is_open()){
        std::string line = "";
        while(getline(shaderStream, line))
            result += "\n" + line;
        shaderStream.close();
        return true;
    }else{
        printf("打开顶点Shader文件 %s 失败，你是否在正确的文件夹下", path);
        getchar();
        return false;
    }
}
