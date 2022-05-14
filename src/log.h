#pragma once
#include <memory>
#include "spdlog/spdlog.h"

class Log
{
public:
    static void init();

    template<typename ...TArgs>
    static void trace(TArgs... args) { _logger->trace(args...); }

    template<typename ...TArgs>
    static void info(TArgs... args) { _logger->info(args...); }

    template<typename ...TArgs>
    static void warn(TArgs... args) { _logger->warn(args...); }

    template<typename ...TArgs>
    static void error(TArgs... args) { _logger->error(args...); }

private:
    static std::shared_ptr<spdlog::logger> _logger;
};