
#include "saunabot.hpp"

namespace saunabot {

void Run()
{
    const std::string token = saunabot::utils::ReadToken();
    auto manager = std::make_unique<saunabot::Manager>(token);

    manager->Start();
}

} // namespace saunabot
