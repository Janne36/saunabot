#pragma once

#include <dpp/dpp.h>

#include <memory>

#include "config/configHandler.hpp"
#include "eventHandler/eventHandler.hpp"
#include "resources/constants.hpp"
#include "utils/logger.hpp"
#include "utils/utils.hpp"

namespace saunabot {

class Manager
{
  public:
    Manager(std::shared_ptr<config::ConfigHandler> &configHandler);
    ~Manager();

    void Start();

  private:
    void SetDppLogHandle();
    void InitSlashCmds();
    void InitOnReady();

    // void GetEmojis();

    std::unique_ptr<dpp::cluster> bot_;
    std::unique_ptr<EventHandler> eventHandler_;
    std::shared_ptr<config::ConfigHandler> configHandler_;
};

} // namespace saunabot
