#pragma once

#include <dpp/dpp.h>

#include "events/baseEvent.hpp"
#include "events/beerEvent.hpp"
#include "events/pingEvent.hpp"
#include "resources/constants.hpp"
#include "utils/logger.hpp"
#include "utils/utils.hpp"

namespace saunabot {

class EventHandler
{
public:
    EventHandler();
    ~EventHandler() = default;

    auto GetEvents() -> std::unordered_map<std::string, std::string>;
    void Handle(const dpp::slashcommand_t &event);

private:
    BaseEvent *FindEvent(const std::string &eventName);

    std::vector<std::unique_ptr<BaseEvent>> events_;
};

} // namespace saunabot
