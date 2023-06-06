#pragma once

#include <dpp/dpp.h>

#include "resources/constants.hpp"
#include "utils/utils.hpp"
#include "utils/logger.hpp"
#include "events/baseEvent.hpp"
#include "events/pingEvent.hpp"
#include "events/beerEvent.hpp"

namespace saunabot {

class EventHandler
{
public:
    EventHandler();
    ~EventHandler() = default;
    
    auto GetEvents() -> std::unordered_map<std::string, std::string>;
    void Handle(const dpp::slashcommand_t& event);

private:
    BaseEvent* FindEvent(const std::string& eventName);

    std::vector<std::unique_ptr<BaseEvent>> events_;
};

} //namespace saunabot
