#pragma once

#include "utils/logger.hpp"
#include "resources/constants.hpp"

namespace saunabot {

class BaseEvent
{
public:
    BaseEvent(const std::string& name): name(name) {};
    ~BaseEvent() = default;

    virtual void Execute(const dpp::slashcommand_t& event) = 0;

    const std::string GetName()
    {
        return this->name;
    }

private:
    std::string name = "";
    //bool callback = false;
};

} // namespace saunabot
