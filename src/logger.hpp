
#include <spdlog/spdlog.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

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

    void Init();
    void Log(const std::string& msg);
    void LogDpp(const std::string& msg);

private:
    Logger() = default;
    static Logger& instance;

    std::shared_ptr<spdlog::logger> logger_;
    std::shared_ptr<spdlog::logger> dppLogger_;
};

} //namespace saunabot
