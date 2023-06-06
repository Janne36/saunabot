
#include "logger.hpp"

namespace saunabot {
namespace utils {

void Logger::Init(std::shared_ptr<config::ConfigHandler>& configHandler)
{
    configHandler_ = configHandler;

    auto stdoutSink = std::make_shared<spdlog::sinks::stdout_sink_st>();
    // TODO: Get rest of the setting from config
    auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_st>(configHandler_->GetLogPath(), 1024 * 1024, 3, true);
    const std::vector<spdlog::sink_ptr> sinks {stdoutSink, fileSink};

    // Log messages from different sources under different names
    this->CreateLogger(resources::constants::LOGGER_NAME_1, sinks);
    this->CreateLogger(resources::constants::LOGGER_NAME_2, sinks);

    this->Info("Loggers initialized");
}

// Log stuff from saunabot itself
void Logger::Info(const std::string& msg)
{
    loggers_.at(resources::constants::LOGGER_NAME_1)->info(msg);
}

void Logger::Warn(const std::string& msg)
{
    loggers_.at(resources::constants::LOGGER_NAME_1)->warn(msg);
}

void Logger::Error(const std::string& msg)
{
    loggers_.at(resources::constants::LOGGER_NAME_1)->error(msg);
}

void Logger::Debug(const std::string& msg)
{
    loggers_.at(resources::constants::LOGGER_NAME_1)->debug(msg);
}

// Log events from Dpp lib only
void Logger::Dpp(const std::string& msg)
{
    // TODO: Severity
   loggers_.at(resources::constants::LOGGER_NAME_2)->info(msg);
}

void Logger::CreateLogger(const std::string& name, const std::vector<spdlog::sink_ptr>& sinks)
{
    auto newLogger = std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());
    newLogger->flush_on(spdlog::level::debug);
    newLogger->set_level(spdlog::level::debug);
    
    loggers_.emplace(name, newLogger);
}

} //namespace utils
} //namespace saunabot
