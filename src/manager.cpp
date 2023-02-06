#include "manager.hpp"

namespace saunabot {

Manager::Manager(const std::string& token)
{
    bot_ = std::make_unique<dpp::cluster>(token);
    bot_->on_log(dpp::utility::cout_logger());

    this->InitSlashCmds();
    this->InitOnReady();

    eventHandler_ = std::make_unique<EventHandler>();
}

Manager::~Manager()
{
    bot_->shutdown();
}

void Manager::Start()
{
    bot_->start(false);
}

void Manager::InitSlashCmds()
{
    bot_->on_slashcommand([this](const dpp::slashcommand_t& event) {
        const auto cmdName = event.command.get_command_name();

        if (cmdName == resources::cmds::PING) {
            eventHandler_->Ping(event);
        }
        else if (cmdName == resources::cmds::VERSION) {
            eventHandler_->Version(event);
        }
        else if (cmdName == resources::cmds::BEER) {
            eventHandler_->Beer(event);
        }
        else {
            event.reply("Töh, täh?");
        }
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
