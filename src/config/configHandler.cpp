
#include "configHandler.hpp"

namespace saunabot {
namespace config {

ConfigHandler::ConfigHandler() { Init(); }

const std::string ConfigHandler::GetTokenPath() { return cfg_.lookup("tokenPath"); }

const std::string ConfigHandler::GetLogPath() { return cfg_.lookup("logPath"); }

void ConfigHandler::Init()
{
    try
    {
        cfg_.readFile("/usr/local/etc/saunabot/config.cfg");
    }
    catch (const libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while reading file." << "\n";
        throw fioex;
    }
    catch (const libconfig::ParseException &pex)
    {
        const auto file = std::string(pex.getFile());
        const auto line = std::to_string(pex.getLine());
        const auto err = std::string(pex.getError());

        std::cerr << "Parse error at" + file + ":" + line + "\n: " + err << "\n";
        throw pex;
    }
    catch (...)
    {
        std::cerr << "ConfigHandler::Init unknown failure" << "\n";
        throw;
    }
}

} // namespace config
} // namespace saunabot
