//
// Created by 董宸 on 05/01/2018.
//

#include <cstdio>
#include <glew/glew.h>
#include "GLWindow.hpp"

namespace ReOpenGL{

    GLWindow::GLWindow() :
            width(800),
            height(600),
            keyCallback(nullptr),
            framebufferSizeCallback(nullptr)
    {
    }

    GLWindow::GLWindow(int width, int height){
        this->width = width;
        this->height = height;
    }


    void GLWindow::Show() {

        if( !glfwInit() )
        {
            fprintf( stderr, "Failed to initialize GLFW\n" );
            getchar();
            return;
        }
        //基本设置
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac系统需要加上这一句
#endif
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        //创建窗口
        window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
        if( window == NULL ){
            fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
            getchar();
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        //设置回调
        if(!keyCallback)
            keyCallback = GLWindow::DefaultKeyCallback;
        glfwSetKeyCallback(window, keyCallback);

        if(!framebufferSizeCallback)
            framebufferSizeCallback = GLWindow::DefaultFramebufferSizeCallback;
        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);


        //
        glewExperimental = GL_TRUE;
        //初始化glew
        glewInit();

        //定义viewport
        int portWidth, portHeight;
        glfwGetFramebufferSize(window, &portWidth, &portHeight);
        glViewport(0, 0, portWidth, portHeight);

    }

    GLFWwindow *GLWindow::getWindow() const {
        return window;
    }

    int GLWindow::getWidth() const {
        return width;
    }

    void GLWindow::setWidth(int width) {
        GLWindow::width = width;
    }

    int GLWindow::getHeight() const {
        return height;
    }

    void GLWindow::setHeight(int height) {
        GLWindow::height = height;
    }

    void GLWindow::setInputCallback(GLFWkeyfun inputCallback) {
        this->keyCallback = inputCallback;
    }

    void GLWindow::setFramebufferSizeCallback(GLFWframebuffersizefun framebufferSizeCallback) {
        this->framebufferSizeCallback = framebufferSizeCallback;
    }

    bool GLWindow::ShouldClose() {
        return (bool)glfwWindowShouldClose(window);
    }




}

