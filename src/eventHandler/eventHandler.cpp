
#include "eventHandler.hpp"

namespace saunabot {

EventHandler::EventHandler()
{
    // Initiase available events.
    auto pingEvent = std::make_unique<PingEvent>();
    auto beerEvent = std::make_unique<BeerEvent>();

    events_.push_back(std::move(pingEvent));
    events_.push_back(std::move(beerEvent));
}

void EventHandler::Handle(const dpp::slashcommand_t& event)
{
    const auto cmdName = event.command.get_command_name();
    auto* foundEvent = this->FindEvent(cmdName);
    
    if(foundEvent != nullptr)
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

BaseEvent* EventHandler::FindEvent(const std::string& eventName)
{
    auto findByName = [&eventName](const std::unique_ptr<BaseEvent>& event)
    {   
        return event->GetName() == eventName;
    };
    auto it = std::find_if(this->events_.begin(), this->events_.end(), findByName);
    if (it != events_.end())
    {
        return it->get();
    }
    return nullptr;  
}

} //namespace saunabot
