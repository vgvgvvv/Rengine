//
// Created by 董宸 on 30/01/2018.
//

#ifndef LEARNINGOPENGL_GLMESH_HPP
#define LEARNINGOPENGL_GLMESH_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <glew/glew.h>
#include <vector>
#include "GLShader.hpp"

namespace ReOpenGL{
    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };

    struct Texture {
        GLuint id;
        std::string type;
        std::string path;
    };

    class GLMesh {
    public:
        /*  网格数据  */
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;
        /*  函数  */
        GLMesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
        void Draw(GLShader shader);
    private:
        /*  渲染数据  */
        GLuint VAO, VBO, EBO;
        /*  初始化函数  */
        void SetupMesh();
    };

}


#endif //LEARNINGOPENGL_GLMESH_HPP
