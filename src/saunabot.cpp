
#include "saunabot.hpp"

namespace saunabot {

void Run()
{
    auto configHandler = std::make_shared<config::ConfigHandler>();
    utils::Logger::Instance().Init(configHandler);

    auto manager = std::make_unique<saunabot::Manager>(configHandler);
    manager->Start();
}

} // namespace saunabot
