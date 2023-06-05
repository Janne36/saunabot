#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <unordered_map>

#define LOG_INFO(MSG) Logger::Instance().Info(MSG)
#define LOG_WARN(MSG) Logger::Instance().Warn(MSG)
#define LOG_ERROR(MSG) Logger::Instance().Error(MSG)
#define LOG_DEBUG(MSG) Logger::Instance().Debug(MSG)
#define LOG_DPP(MSG) Logger::Instance().Dpp(MSG)

namespace saunabot {

class Logger
{
public:
    static Logger& Instance()
    {
        static Logger instance;
        return instance;
    }
    Logger(Logger const&) = delete;
    void operator=(Logger const&)  = delete;

    void Init(const std::string& logPath);
    
    void Info(const std::string& msg);
    void Warn(const std::string& msg);
    void Error(const std::string& msg);
    void Debug(const std::string& msg);
    void Dpp(const std::string& msg);

private:
    Logger() = default;
    static Logger& instance;

    std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> loggers_;
};

} //namespace saunabot
