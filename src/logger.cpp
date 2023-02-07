
#include "logger.hpp"

namespace saunabot {

void Logger::Init()
{
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
    //sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_st>("logs/multisink.txt", 1048576 * 5, 3));

    // Log messages from different sources under different names
    auto saunaLogger = std::make_shared<spdlog::logger>("saunabot", sinks.begin(), sinks.end());
    auto dppLogger = std::make_shared<spdlog::logger>("dpp", sinks.begin(), sinks.end());

    saunaLogger->set_level(spdlog::level::debug);
    dppLogger->set_level(spdlog::level::debug);

    logger_ = std::move(saunaLogger); // Chop, chop!
    dppLogger_ = std::move(dppLogger);

    this->Log("Saunalogger running and ready");
}

// Log stuff from saunabot itself
void Logger::Log(const std::string& msg)
{
    // TODO: Severity
    logger_->info(msg);
}

// Log events from Dpp lib only
void Logger::LogDpp(const std::string& msg)
{
    // TODO: Severity
    dppLogger_->info(msg);
}

} //namespace saunabot
