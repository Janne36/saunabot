#include "manager.hpp"

#define CREATE_GLOBAL_CMD(name, description)                                       \
    bot_->global_command_create(dpp::slashcommand(name, description, bot_->me.id)) \


namespace saunabot {

Manager::Manager(const std::string& token)
{
    bot_ = std::make_unique<dpp::cluster>(token);
    bot_->on_log(dpp::utility::cout_logger());

    this->InitSlashCmds();
    this->InitOnReady();  
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
        if (event.command.get_command_name() == resources::cmds::PING) {
            event.reply("Pong!");
        }
        else if (event.command.get_command_name() == resources::cmds::VERSION) {
            event.reply(this->version_);
        }
        else if (event.command.get_command_name() == resources::cmds::BEER) {
            event.reply("Kaljaa herralle, olkaa hyvä: <:karhu1L:1069670370099068998>");
        }
    });
}

void Manager::InitOnReady()
{
    bot_->on_ready([this](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            CREATE_GLOBAL_CMD(resources::cmds::PING, "Ping pong!");
            CREATE_GLOBAL_CMD(resources::cmds::VERSION, "Palauttaa botin version");
            CREATE_GLOBAL_CMD(resources::cmds::BEER, "Kaljaa on hyvä juua");
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
