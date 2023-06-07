#pragma once

#include <cstdlib>
#include <iostream>
#include <libconfig.h++>

namespace saunabot {
namespace config {

/**
 * Configuration handler for saunabot
 * Should be loaded first in startup
 */
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

} // namespace config
} // namespace saunabot
