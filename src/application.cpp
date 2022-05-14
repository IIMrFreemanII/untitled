#include "application.h"
#include "log.h"

untitled::Application::Application() {
    Log::init();
}

void untitled::Application::run() {
    Log::trace("hello world");
    Log::info("hello world");
    Log::warn("hello world");
    Log::error("hello world");
}

void untitled::Application::close() {

}
