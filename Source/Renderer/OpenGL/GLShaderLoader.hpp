//
// Created by 董宸 on 05/01/2018.
//

#ifndef LEARNINGOPENGL_SHADER_HPP_H
#define LEARNINGOPENGL_SHADER_HPP_H

namespace ReOpenGL{

    GLuint LoadProgram(const char* vertexFilePath, const char* fragmentFilePath);
    GLuint LoadProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID);
    GLuint LoadShader(const char* shaderPath, const GLenum shaderType);

}


#endif //LEARNINGOPENGL_SHADER_HPP_H
