//
// Created by 董宸 on 07/01/2018.
//

#ifndef LEARNINGOPENGL_GLOLDMESH_HPP
#define LEARNINGOPENGL_GLOLDMESH_HPP

#include "glew/glew.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include <vector>
#include <string>

namespace ReOpenGL{

    struct GLVertexAttribute{
        std::string name;//属性名
        GLint size;//属性尺寸
        GLenum type;//属性类型
        GLboolean normalized;//是否单位化

    };

    class GLOldMesh {
    public:
        /**
         * 创建Mesh
         * @param vertices 顶点数组
         * @param vertexNumber 到底多多少个顶点
         * @param indices indice数组
         * @param indicesNumber indice的数量
         */
        GLOldMesh(GLfloat* vertices, GLint vertexNumber, GLuint indices[], GLint indicesNumber);
        ~GLOldMesh();

        /**
         * 构建Mesh
         */
        void Build();
        void Uninit();

        /**
         * 添加顶点属性
         * @param name 属性名
         * @param size 大小，包含几个数据
         * @param type 数据类型
         * @param normalized 是否单位化
         */
        void AddVertexProperty(GLint size, std::string name, GLenum type, GLboolean normalized);
        /**
         * 用何种方式渲染，例如GL_TRIANGES
         * @param renderType
         */
        void Render(GLenum renderType, GLboolean drawElement = GL_TRUE);

        GLuint getVAO_ID() const;

        GLuint getVBO_ID() const;

        GLuint getEBO_ID() const;

    private:

        GLuint VAO_ID;
        GLuint VBO_ID;
        GLuint EBO_ID;

        GLfloat* vertices;
        GLint vertexNumber;
        GLint vertexSize;

        GLuint* indices;
        GLint indicesNumber;

        GLenum drawType;

        std::vector<GLVertexAttribute> vertexAttrVec;
    };
}

#endif //LEARNINGOPENGL_GLOLDMESH_HPP
