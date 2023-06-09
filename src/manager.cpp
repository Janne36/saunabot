#include "manager.hpp"

namespace saunabot {

Manager::Manager(std::shared_ptr<config::ConfigHandler> &configHandler) : configHandler_(configHandler)
{
    this->InitDppCluster();
    this->SetDppLogHandle();
    this->InitEventHandler();
    this->InitSlashCmds();
    this->InitOnReady();

    LOG_INFO("Manager init done");
}

Manager::~Manager() { bot_->shutdown(); }

void Manager::Start() { bot_->start(false); }

void Manager::InitDppCluster()
{
    const std::string token = saunabot::utils::ReadToken(configHandler_->GetTokenPath());
    bot_ = std::make_unique<dpp::cluster>(token);
}

void Manager::SetDppLogHandle()
{
    bot_->on_log([this](const dpp::log_t &log) {
        // TODO: handle log.severity
        LOG_DPP(log.message);
    });
}

void Manager::InitEventHandler()
{
    // Add events to be created and managed to this vector
    std::vector<std::unique_ptr<BaseEvent>> events{};
    events.emplace_back(std::make_unique<PingEvent>());
    events.emplace_back(std::make_unique<BeerEvent>());

    eventHandler_ = std::make_unique<EventHandler>(std::move(events));
}

void Manager::InitSlashCmds()
{
    bot_->on_slashcommand(
        [this](const dpp::slashcommand_t &event) { this->eventHandler_->Handle(event); });
}

void Manager::InitOnReady()
{
    bot_->on_ready([this](const dpp::ready_t &event) {
        if (dpp::run_once<struct register_bot_commands>())
        {
            for (const auto slashCmd : this->eventHandler_->GetSlashCmds(bot_->me.id))
            {
                bot_->global_command_create(slashCmd);
            }
        }
    });
}

/*
void Manager::GetEmojis()
{
    bot_->guild_emojis_get(resources::constants::SAUNA_ID, [this](const
dpp::confirmation_callback_t& callback) -> dpp::confirmation_callback_t& {

    });
}
*/

} // namespace saunabot
