//
// Created by 董宸 on 05/01/2018.
//

#ifndef LEARNINGOPENGL_GLSHADER_HPP
#define LEARNINGOPENGL_GLSHADER_HPP

#include <string>
#include "glew/glew.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

namespace ReOpenGL{

    class GLShader {
    public:

        /**
         * 初始化
         * @param vertexShaderPath
         * @param fragmentShaderPath
         */
        GLShader(const char* vertexShaderPath, const char* fragmentShaderPath);
        /**
         * 使用Shader程序
         */
        void Use();
        /**
         * 设置Bool值
         * @param name
         * @param value
         */
        void SetBool(const std::string name, bool value) const;
        /**
         * 设置Int值
         * @param name
         * @param value
         */
        void SetInt(const std::string name, int value) const;
        /**
         * 设置Float值
         * @param name
         * @param value
         */
        void SetFloat(const std::string name, float value) const;
        void SetVec2(const std::string &name, const glm::vec2 &value) const;
        void SetVec2(const std::string &name, float x, float y) const;
        void SetVec3(const std::string &name, const glm::vec3 &value) const;
        void SetVec3(const std::string &name, float x, float y, float z) const;
        void SetVec4(const std::string &name, const glm::vec4 &value) const;
        void SetVec4(const std::string &name, float x, float y, float z, float w);
        void SetMat2(const std::string &name, const glm::mat2 &mat) const;
        void SetMat3(const std::string &name, const glm::mat3 &mat) const;
        void SetMat4(const std::string &name, const glm::mat4 &mat) const;

        /**
         * 获得ID
         * @return
         */
        GLuint GetProgramID() const;

    private:
        GLuint programID;

    };

}



#endif //LEARNINGOPENGL_GLSHADER_HPP
