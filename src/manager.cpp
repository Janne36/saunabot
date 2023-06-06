#include "manager.hpp"

namespace saunabot {

Manager::Manager(std::shared_ptr<config::ConfigHandler>& configHandler)
{
    configHandler_ = configHandler;

    const std::string token = saunabot::utils::ReadToken(configHandler_->GetTokenPath());

    bot_ = std::make_unique<dpp::cluster>(token);
    eventHandler_ = std::make_unique<EventHandler>();

    this->SetDppLogHandle();
    this->InitSlashCmds();
    this->InitOnReady();

    LOG_INFO("Manager init done");
}

Manager::~Manager()
{
    bot_->shutdown();
}

void Manager::Start()
{
    bot_->start(false);
}

void Manager::SetDppLogHandle()
{
    bot_->on_log([this](const dpp::log_t& log) {
        // TODO: handle log.severity
        //Logger::Instance().LogDpp(log.message);
        LOG_DPP(log.message);
    });
}

void Manager::InitSlashCmds()
{
    bot_->on_slashcommand([this](const dpp::slashcommand_t& event) {
        this->eventHandler_->Handle(event);
    });
}

void Manager::InitOnReady()
{
    bot_->on_ready([this](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            const std::unordered_map<std::string, std::string> cmdsToCreate {
                {resources::cmds::PING, resources::descriptions::PING},
                {resources::cmds::VERSION, resources::descriptions::VERSION },
                {resources::cmds::BEER, resources::descriptions::BEER }
            };
            for (const auto cmd : cmdsToCreate)
            {
                bot_->global_command_create(dpp::slashcommand(cmd.first, cmd.second, bot_->me.id));
            }
        }
    });
}

/*
void Manager::GetEmojis()
{
    bot_->guild_emojis_get(resources::constants::SAUNA_ID, [this](const dpp::confirmation_callback_t& callback) -> dpp::confirmation_callback_t& {

    });
}
*/

} //namespace saunabot
