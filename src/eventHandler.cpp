
#include "eventHandler.hpp"

namespace saunabot {

void EventHandler::Ping(const dpp::slashcommand_t& event)
{
    LOG_DEBUG("Ping event received");
    event.reply(resources::replies::PING);
}

void EventHandler::Version(const dpp::slashcommand_t& event)
{
    LOG_DEBUG("Version event received");
    event.reply(resources::constants::VERSION);
}

void EventHandler::Beer(const dpp::slashcommand_t& event)
{
    LOG_DEBUG("Beer event received");
    const auto randomReply = utils::PickRandom(resources::replies::beerReg);
    event.reply(randomReply + ": <:karhu1L:1069670370099068998>");
}

} //namespace saunabot
