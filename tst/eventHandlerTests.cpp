#include "eventHandler/eventHandler.hpp"
#include <gtest/gtest.h>
#include "gmock/gmock.h"

namespace test {

/*
struct SlashCommandMock : public dpp::slashcommand_t
{
public:
    SlashCommandMock(class dpp::discord_client& client, const std::string& raw) : dpp::slashcommand_t(&client, raw) {};

    MOCK_METHOD(void, reply, (dpp::command_completion_event_t callback), (const));

};
*/

class EventHandlerTests : public testing::Test
{
public:
    void SetUp() override { sut_ = std::make_unique<saunabot::EventHandler>(); }

    std::unique_ptr<saunabot::EventHandler> sut_;
};

TEST_F(EventHandlerTests, ServeBeer)
{
    dpp::cluster cluster("");
    dpp::discord_client client(&cluster, 1, 1, "");
    dpp::interaction_create_t interaction(&client, "");

    const std::string cmd = "/kaljaa";
    auto event = dpp::slashcommand_t(&client, cmd);
    //auto event = testing::StrictMock<SlashCommandMock>(client, cmd);
    //event.get_parameter
    EXPECT_NO_THROW(sut_->Handle(event));

    //auto reply = event.reply();
}

} // namespace test
