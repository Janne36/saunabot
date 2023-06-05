#pragma once

#include <libconfig.h++>
#include <cstdlib>
#include <iostream>
#include "logger.hpp"

namespace saunabot {
namespace config {

class ConfigHandler
{
public: 
    ConfigHandler();
    ~ConfigHandler() = default;

    const std::string GetTokenPath();
    const std::string GetLogPath();

private:
    void Init();

    libconfig::Config cfg_;
};

} //namespace config
} //namespace saunabot
