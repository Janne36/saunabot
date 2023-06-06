#pragma once

#include "baseEvent.hpp"

namespace saunabot {

class PingEvent : public BaseEvent
{
public:
    PingEvent(): BaseEvent(resources::cmds::PING, resources::descriptions::PING) {}

    void Execute(const dpp::slashcommand_t& event) override
    {
        LOG_DEBUG("Ping event received");
        event.reply(resources::replies::PING);
    };
};

} // namespace saunabot
