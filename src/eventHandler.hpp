#pragma once

#include <dpp/dpp.h>

#include "resources/constants.hpp"
#include "utils/utils.hpp"
#include "logger.hpp"

namespace saunabot {

class EventHandler
{
public:
    EventHandler() = default;
    ~EventHandler() = default;

    void Ping(const dpp::slashcommand_t& event);
    void Version(const dpp::slashcommand_t& event);
    void Beer(const dpp::slashcommand_t& event);
};

} //namespace saunabot
