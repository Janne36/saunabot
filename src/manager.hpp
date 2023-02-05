#pragma once

#include <dpp/dpp.h>
#include <memory>

#include "utils/utils.hpp"
#include "resources/constants.hpp"

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
    const std::string version_ = "0.0.2";
};

} //namespace saunabot
