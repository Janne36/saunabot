#pragma once

#include "baseEvent.hpp"
#include "utils/utils.hpp"

namespace saunabot {

class BeerEvent : public BaseEvent
{
public:
    BeerEvent(): BaseEvent(resources::cmds::BEER) {}

    void Execute(const dpp::slashcommand_t& event) override
    {
        LOG_DEBUG("Beer event received");
        const auto randomReply = utils::PickRandom(resources::replies::beerReg);
        event.reply(randomReply + ": <:karhu1L:1069670370099068998>");
    };
};

} // namespace saunabot
