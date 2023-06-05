
#include "saunabot.hpp"

namespace saunabot {

void Run()
{
    auto manager = std::make_unique<saunabot::Manager>();
    manager->Start();
}

} // namespace saunabot
