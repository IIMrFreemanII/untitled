#include "application.h"
#include "log.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

untitled::Application::Application() {
    Log::init();
}

void untitled::Application::run() {
    Log::info("Start application");

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return;

    // Minimum target is OpenGL 4.1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    if (!status) {
        Log::error("Failed to initialize Glad!");
    }

    Log::info("OpenGL Info:");
    Log::info("  Vendor: {0}", glGetString(GL_VENDOR));
    Log::info("  Renderer: {0}", glGetString(GL_RENDERER));
    Log::info("  Version: {0}", glGetString(GL_VERSION));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}

void untitled::Application::close() {

}
