//
// Created by 董宸 on 05/01/2018.
//

#include "glew/glew.h"
#include "glfw/glfw3.h"

#include "GLShader.hpp"
#include "GLShaderLoader.hpp"


namespace ReOpenGL{

    GLShader::GLShader(const char *vertexShaderPath, const char *fragmentShaderPath) {
        this->programID = LoadProgram(vertexShaderPath, fragmentShaderPath);
    }

    void GLShader::Use() {
        glUseProgram(this->programID);
    }

    void GLShader::SetBool(const std::string name, bool value) const {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), (int)value);
    }

    void GLShader::SetInt(const std::string name, int value) const {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), value);
    }

    void GLShader::SetFloat(const std::string name, float value) const {
        glUniform1i(glGetUniformLocation(this->programID, name.c_str()), value);
    }

    // ------------------------------------------------------------------------
    void GLShader::SetVec2(const std::string &name, const glm::vec2 &value) const
    {
        glUniform2fv(glGetUniformLocation(this->programID, name.c_str()), 1, &value[0]);
    }
    void GLShader::SetVec2(const std::string &name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(this->programID, name.c_str()), x, y);
    }
    // ------------------------------------------------------------------------
    void GLShader::SetVec3(const std::string &name, const glm::vec3 &value) const
    {
        glUniform3fv(glGetUniformLocation(this->programID, name.c_str()), 1, &value[0]);
    }
    void GLShader::SetVec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(this->programID, name.c_str()), x, y, z);
    }
    // ------------------------------------------------------------------------
    void GLShader::SetVec4(const std::string &name, const glm::vec4 &value) const
    {
        glUniform4fv(glGetUniformLocation(this->programID, name.c_str()), 1, &value[0]);
    }
    void GLShader::SetVec4(const std::string &name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(this->programID, name.c_str()), x, y, z, w);
    }
    // ------------------------------------------------------------------------
    void GLShader::SetMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(this->programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void GLShader::SetMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(this->programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void GLShader::SetMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(this->programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }


    GLuint GLShader::GetProgramID() const {
        return programID;
    }

}

