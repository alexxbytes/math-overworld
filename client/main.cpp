#include <iostream>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "windows/BackdropController/win.cpp"
#include "windows/BackdropController/winstyle.h"
#include "windows/BackdropController/dwm.cpp"
#include "windows/BackdropController/user32.cpp"
#include "windows/BackdropController/types.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

int main() {
    std::cout << "Hi World!" << "\n";

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        std::cerr << "Failed to initalize the library." << "\n";
        return -1;
    }

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(990, 600, "Hi World!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //Mica
    enableDWM();
    HWND hwnd = glfwGetWin32Window(window);
    applyMicaEffect(0x02, hwnd);
    setAppTheme(1, hwnd);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //VSync
    glfwSwapInterval(1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}