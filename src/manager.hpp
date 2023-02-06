#pragma once

#include <dpp/dpp.h>
#include <memory>

#include "utils/utils.hpp"
#include "resources/constants.hpp"
#include "eventHandler.hpp"

namespace saunabot {

class Manager
{
public:
    Manager(const std::string& token);
    ~Manager();

    void Start();

private:
    void InitSlashCmds();
    void InitOnReady();

    //void GetEmojis();

    std::unique_ptr<dpp::cluster> bot_;
    std::unique_ptr<EventHandler> eventHandler_;
};

} //namespace saunabot
