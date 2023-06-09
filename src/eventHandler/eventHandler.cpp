
#include "eventHandler.hpp"

namespace saunabot {

EventHandler::EventHandler(std::vector<std::unique_ptr<BaseEvent>> events) : events_(std::move(events))
{}

auto EventHandler::GetSlashCmds(const dpp::snowflake id) -> std::vector<dpp::slashcommand>
{
    std::vector<dpp::slashcommand> foundEvents{};
    for (const auto &it : this->events_)
    {
        foundEvents.push_back(it->CreateSlashCmd(id));
    }
    if (foundEvents.empty())
    {
        LOG_WARN("No events found!");
    }
    return foundEvents;
}

void EventHandler::Handle(const dpp::slashcommand_t &event)
{
    const auto cmdName = event.command.get_command_name();
    auto *foundEvent = this->FindEvent(cmdName);

    if (foundEvent != nullptr)
    {
        LOG_DEBUG("Event found: " + cmdName);
        foundEvent->Execute(event);
    }
    else
    {
        LOG_ERROR("Could not find event: " + cmdName);
        event.reply("Töh, täh?");
    }
}

BaseEvent *EventHandler::FindEvent(const std::string &eventName)
{
    auto findByName = [&eventName](const std::unique_ptr<BaseEvent> &event) {
        return event->GetName() == eventName;
    };
    auto it = std::find_if(this->events_.begin(), this->events_.end(), findByName);
    if (it != events_.end())
    {
        return it->get();
    }
    return nullptr;
}

} // namespace saunabot
