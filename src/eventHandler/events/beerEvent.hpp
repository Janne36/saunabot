#pragma once

#include "baseEvent.hpp"
#include "utils/utils.hpp"

namespace saunabot {

class BeerEvent : public BaseEvent
{
public:
    BeerEvent() : BaseEvent(resources::cmds::BEER, resources::descriptions::BEER) {}

    void Execute(const dpp::slashcommand_t &event) override
    {
        //event.get_parameter()

        LOG_DEBUG("Beer event received " + event.raw_event);

        event.reply(this->CreateReply());
    };

    dpp::slashcommand CreateSlashCmd(const dpp::snowflake id) override
    {
        dpp::slashcommand cmd(this->name, this->description, id);
        // TODO: ...
        return cmd;
    }

private:
    std::string CreateReply()
    {
        const auto randomReply = utils::PickRandom(resources::replies::beerReg);
        return randomReply + ": <:karhu1L:1069670370099068998>";
    }
};

} // namespace saunabot
