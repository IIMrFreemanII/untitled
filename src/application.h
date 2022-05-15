#pragma once

#define GLFW_INCLUDE_VULKAN

#include <vector>

#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"

const std::vector<const char*> validationLayers = {
  "VK_LAYER_KHRONOS_validation"
};
const std::vector<const char*> deviceExtensions = {
  VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

namespace untitled {
  class Application {
  public:
    int width = 800;
    int height = 600;

  public:
    Application();

    void run();

    void close();

  private:
    GLFWwindow* _window;
    VkInstance _instance;
    VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
    VkDevice _device;
    VkQueue _graphicsQueue;
    VkQueue _presentQueue;
    VkSurfaceKHR _surface;
    VkSwapchainKHR _swapChain;
    std::vector<VkImage> _swapChainImages;
    VkFormat _swapChainImageFormat;
    VkExtent2D _swapChainExtent;
    std::vector<VkImageView> _swapChainImageViews;

  private:
    void initWindow();

    void createInstance();

    bool checkValidationLayerSupport();

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSurface();

    void createSwapChain();

    void createImageViews();

    void initVulkan();

    void mainLoop();

    void cleanup();

  };
}
