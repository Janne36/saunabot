#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <unordered_map>
#include <memory>

#include "config/configHandler.hpp"
#include "resources/constants.hpp"

#define LOG_INFO(MSG) utils::Logger::Instance().Info(MSG)
#define LOG_WARN(MSG) utils::Logger::Instance().Warn(MSG)
#define LOG_ERROR(MSG) utils::Logger::Instance().Error(MSG)
#define LOG_DEBUG(MSG) utils::Logger::Instance().Debug(MSG)
#define LOG_DPP(MSG) utils::Logger::Instance().Dpp(MSG)

namespace saunabot {
namespace utils {

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

    void Init(std::shared_ptr<config::ConfigHandler>& configHandler);
    
    void Info(const std::string& msg);
    void Warn(const std::string& msg);
    void Error(const std::string& msg);
    void Debug(const std::string& msg);
    void Dpp(const std::string& msg);

private:
    Logger() = default;
    static Logger& instance;

    void CreateLogger(const std::string& name,  const std::vector<spdlog::sink_ptr>& sinks);

    std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> loggers_;
    std::shared_ptr<config::ConfigHandler> configHandler_;
};

} // namespace utils
} //namespace saunabot
