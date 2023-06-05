
#include "configHandler.hpp"

namespace saunabot {
namespace config {

ConfigHandler::ConfigHandler()
{
    Init();
}

const std::string ConfigHandler::GetTokenPath()
{
    return cfg_.lookup("tokenPath");
}

const std::string ConfigHandler::GetLogPath()
{
    return cfg_.lookup("logPath");
}

void ConfigHandler::Init()
{
    try
    {
        cfg_.readFile("config.cfg");
    }
    catch(const libconfig::FileIOException& fioex)
    {

        throw "I/O error while reading file.";
    }
    catch(const libconfig::ParseException& pex)
    {
        const auto file = std::string(pex.getFile());
        const auto line = std::to_string(pex.getLine());
        const auto err = std::string(pex.getError());

        throw "Parse error at" + file + ":" + line + "\n: " + err;
    }
    catch(...)
    {
        throw "ConfigHandler::Init unknown failure";
    }
}

} //namespace config
} //namespace saunabot
