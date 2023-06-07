
#include "utils/logger.hpp"

namespace saunabot {
namespace utils {

void Logger::Init(std::shared_ptr<config::ConfigHandler> &configHandler)
{
    (void)configHandler;
}

// Log stuff from saunabot itself
void Logger::Info(const std::string &msg)
{
    std::cout << msg << "\n";
}

void Logger::Warn(const std::string &msg)
{
    std::cout << msg << "\n";
}

void Logger::Error(const std::string &msg)
{
    std::cout << msg << "\n";
}

void Logger::Debug(const std::string &msg)
{
    std::cout << msg << "\n";
}

void Logger::Dpp(const std::string &msg)
{

    std::cout << msg << "\n";
}

} // namespace utils
} // namespace saunabot
