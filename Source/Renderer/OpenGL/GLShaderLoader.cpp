#include <stdio.h>

#include <iostream>

using namespace std;

#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <Common.hpp>

#include "glew/glew.h"
#include "glfw/glfw3.h"
#include "GLShaderLoader.hpp"

namespace ReOpenGL{
    GLuint LoadProgram(const char* vertexFilePath, const char* fragmentFilePath);
    GLuint LoadProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID);
    GLuint LoadShader(const char* shaderPath, const GLenum shaderType);

/**
 * 加载程序
 * @param vertexFilePath
 * @param fragmentFilePath
 * @return
 */
    GLuint LoadProgram(const char* vertexFilePath, const char* fragmentFilePath){

        GLuint vertexShaderID = LoadShader(vertexFilePath, GL_VERTEX_SHADER);
        GLuint fragmentShaderID = LoadShader(fragmentFilePath, GL_FRAGMENT_SHADER);

        return LoadProgram(vertexShaderID, fragmentShaderID);

    }

/**
 * 加载程序
 * @param vertexShaderID
 * @param fragmentShaderID
 * @return
 */
    GLuint LoadProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID){

        printf("链接程序\n");
        GLuint programID = glCreateProgram();
        glAttachShader(programID, vertexShaderID);
        glAttachShader(programID, fragmentShaderID);
        glLinkProgram(programID);

        //检查程序
        GLint linkResult = GL_FALSE;
        int linkInfoLog;
        glGetProgramiv(programID, GL_LINK_STATUS, &linkResult);
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &linkInfoLog);
        if(linkInfoLog > 0){
            std::vector<char> programErrorMessage(linkInfoLog+1);
            glGetShaderInfoLog(programID, linkInfoLog, NULL, &programErrorMessage[0]);
            printf("%s\n", programErrorMessage[0]);
        }

        glDetachShader(programID, vertexShaderID);
        glDetachShader(programID, fragmentShaderID);

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return programID;
    }

/**
 * 加载Shader
 * @param shaderPath
 * @param shaderType
 * @return
 */
    GLuint LoadShader(const char* shaderPath, const GLenum shaderType){

        GLuint shaderID = glCreateShader(shaderType);
        //读取Shader代码
        std::string shaderCode;

        if(!ReadFile(shaderPath, shaderCode)){
            return 0;
        }

        //编译顶点Shader
        printf("编译Shader：%s\n", shaderPath);
        char const* vertexSourcePointer = shaderCode.c_str();
        glShaderSource(shaderID, 1, &vertexSourcePointer, NULL);
        glCompileShader(shaderID);

        //检查顶点Shader
        GLint compileShaderResult = GL_FALSE;
        int infoLogLength;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileShaderResult);
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0){
            std::vector<char> shaderErrorMessage(infoLogLength+1);
            glGetShaderInfoLog(shaderID, infoLogLength, NULL, &shaderErrorMessage[0]);
            printf("%s\n", &shaderErrorMessage[0]);
        }

        return shaderID;
    }
}
