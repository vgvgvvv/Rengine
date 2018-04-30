//
// Created by 董宸 on 05/01/2018.
//

#ifndef LEARNINGOPENGL_WINDOW_HPP
#define LEARNINGOPENGL_WINDOW_HPP

#include <glfw/glfw3.h>

namespace ReOpenGL{

    class GLWindow {
    public:

        GLWindow();
        GLWindow(int width, int height);

        void Show();

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        void setInputCallback(GLFWkeyfun const);

        void setFramebufferSizeCallback(GLFWframebuffersizefun const);

        GLFWwindow *getWindow() const;

        bool ShouldClose();

        static void DefaultProcessInput(GLFWwindow *window) {
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
        }

        static void DefaultFramebufferSizeCallback(GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        static void DefaultKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
        }

    private:

        int width;
        int height;
        GLFWkeyfun keyCallback;
        GLFWframebuffersizefun framebufferSizeCallback;
        GLFWwindow* window;
    };

}



#endif //LEARNINGOPENGL_WINDOW_HPP
