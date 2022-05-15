#include "application.h"
#include "log.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

untitled::Application::Application() {
    Log::init();
}

void untitled::Application::run() {
    Log::info("Start application");

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    Log::info("{} extensions supported", extensionCount);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwTerminate();
}

void untitled::Application::close() {

}
