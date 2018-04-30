//
// Created by 董宸 on 30/01/2018.
//

#ifndef LEARNINGOPENGL_GLMODEL_HPP
#define LEARNINGOPENGL_GLMODEL_HPP

#include "GLShader.hpp"
#include "GLMesh.hpp"
#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

namespace ReOpenGL{
    class GLModel {
    public:
        /*  函数   */
        GLModel(char *path)
        {
            loadModel(path);
        }
        /*
         * 绘制模型
         */
        void Draw(GLShader shader);
    private:
        /*  模型数据  */
        std::vector<GLMesh> meshes;
        std::string directory;
        /*  函数   */
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        GLMesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    };
}



#endif //LEARNINGOPENGL_GLMODEL_HPP
