#pragma once

#include "resources/constants.hpp"
#include "utils/logger.hpp"

namespace saunabot {

class BaseEvent
{
  public:
    BaseEvent(const std::string &name, const std::string &description)
        : name(name), description(description){};
    ~BaseEvent() = default;

    virtual void Execute(const dpp::slashcommand_t &event) = 0;
    // virtual void Callback(const dpp::confirmation_callback_t&);

    const std::string GetName() { return this->name; }
    const std::string GetDescription() { return this->description; }

  private:
    const std::string name = "";
    const std::string description = "";
    // bool callback = false;
};

} // namespace saunabot
