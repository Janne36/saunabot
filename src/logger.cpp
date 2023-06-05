
#include "logger.hpp"

namespace saunabot {

void Logger::Init(const std::string& logPath)
{
    auto stdoutSink = std::make_shared<spdlog::sinks::stdout_sink_st>();
    stdoutSink->set_level(spdlog::level::debug);

    auto fileSink = std::make_shared<spdlog::sinks::rotating_file_sink_st>(logPath, 1024 * 1024, 3, true);
    fileSink->set_level(spdlog::level::debug);

    const std::vector<spdlog::sink_ptr> sinks {stdoutSink, fileSink};

    // Log messages from different sources under different names
    auto saunaLogger = std::make_shared<spdlog::logger>("sauna", sinks.begin(), sinks.end());
    auto dppLogger = std::make_shared<spdlog::logger>("dpp", sinks.begin(), sinks.end());

    saunaLogger->flush_on(spdlog::level::info);
    dppLogger->flush_on(spdlog::level::info);

    loggers_.emplace("sauna", saunaLogger);
    loggers_.emplace("dpp", dppLogger);

    this->Info("Saunalogger running and ready");
}

// Log stuff from saunabot itself
void Logger::Info(const std::string& msg)
{
    //saunaLogger_->info(msg);
    loggers_.at("sauna")->info(msg);
}

void Logger::Warn(const std::string& msg)
{
    loggers_.at("sauna")->warn(msg);
}

void Logger::Error(const std::string& msg)
{
    loggers_.at("sauna")->error(msg);
}

void Logger::Debug(const std::string& msg)
{
    loggers_.at("sauna")->debug(msg);
}

// Log events from Dpp lib only
void Logger::Dpp(const std::string& msg)
{
    // TODO: Severity
   loggers_.at("dpp")->info(msg);
}

} //namespace saunabot
