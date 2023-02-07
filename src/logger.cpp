
#include "logger.hpp"

namespace saunabot {

void Logger::Init()
{
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
    //sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_st>("logs/multisink.txt", 1048576 * 5, 3));

    auto saunalogger = std::make_shared<spdlog::logger>("saunalogger", sinks.begin(), sinks.end());

    saunalogger->set_level(spdlog::level::debug);
    spdlog::register_logger(saunalogger);

    // Chop, chop!
    logger_ = spdlog::get("saunalogger");
    this->Log("Saunalogger running and ready");
}

void Logger::Log(const std::string& msg)
{
    // TODO: Severity
    logger_->info(msg);
}

} //namespace saunabot
