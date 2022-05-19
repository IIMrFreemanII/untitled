#pragma once

#define GLFW_INCLUDE_VULKAN

#include <vector>

#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"

const std::vector<const char*> validationLayers = {
  "VK_LAYER_KHRONOS_validation"
};
const std::vector<const char*> deviceExtensions = {
  VK_KHR_SWAPCHAIN_EXTENSION_NAME,
//  "VK_KHR_portability_subset"
};

// todo: use this for setting vk instance extensions and fix errors
const std::vector<const char*> instanceExtensions = {
  "VK_KHR_get_physical_device_properties2",
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
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR _surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> _swapChainImages;
    VkFormat _swapChainImageFormat;
    VkExtent2D _swapChainExtent;
    std::vector<VkImageView> _swapChainImageViews;
    VkRenderPass _renderPass;
    VkPipelineLayout _pipelineLayout;
    VkPipeline _graphicsPipeline;
    std::vector<VkFramebuffer> _swapChainFrameBuffers;
    VkCommandPool _commandPool;
    VkCommandBuffer commandBuffer;

    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;

  private:
    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();

    void createInstance();

    bool checkValidationLayerSupport();

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSurface();

    void createSwapChain();

    void createImageViews();

    void createGraphicsPipeline();

    VkShaderModule createShaderModule(const std::vector<char>& code);

    void createRenderPass();

    void createFrameBuffers();

    void createCommandPool();

    void createCommandBuffer();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void drawFrame();

    void createSyncObjects();
  };
}
