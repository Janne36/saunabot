#pragma once

#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/spdlog.h>

#include <memory>
#include <unordered_map>

#include "config/configHandler.hpp"
#include "resources/constants.hpp"

#define LOGGER utils::Logger::Instance()
#define LOG_INFO(MSG) LOGGER.Info(MSG)
#define LOG_WARN(MSG) LOGGER.Warn(MSG)
#define LOG_ERROR(MSG) LOGGER.Error(MSG)
#define LOG_DEBUG(MSG) LOGGER.Debug(MSG)
#define LOG_DPP(MSG) LOGGER.Dpp(MSG)

namespace saunabot {
namespace utils {

class Logger
{
public:
    static Logger &Instance()
    {
        static Logger instance;
        return instance;
    }
    Logger(Logger const &) = delete;
    void operator=(Logger const &) = delete;

    void Init(std::shared_ptr<config::ConfigHandler> &configHandler);

    void Info(const std::string &msg);
    void Warn(const std::string &msg);
    void Error(const std::string &msg);
    void Debug(const std::string &msg);
    void Dpp(const std::string &msg);

private:
    Logger() = default;
    static Logger &instance;

    void CreateLogger(const std::string &name, const std::vector<spdlog::sink_ptr> &sinks);

    std::unordered_map<std::string, std::shared_ptr<spdlog::logger>> loggers_;
    std::shared_ptr<config::ConfigHandler> configHandler_;
};

} // namespace utils
} // namespace saunabot
