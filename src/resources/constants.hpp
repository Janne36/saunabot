#pragma once

namespace saunabot {
namespace resources {

namespace constants {

static const char VERSION[] = "0.0.3";
inline constexpr unsigned long int SAUNA_ID = 1069657680140054679;

} // namespace constants

// TODO: Should perhaps bundle these somehow
namespace cmds {

static const char PING[] = "ping";
static const char VERSION[] = "versio";
static const char BEER[] = "kaljaa";

} // namespace cmds

namespace descriptions {

static const char PING[] = "Ping pong!";
static const char VERSION[] = "Palauttaa botin version";
static const char BEER[] = "Kaljaa on hyvä juua";

} // namespace descriptions

namespace replies {

static const char PING[] = "Pong!";
static const std::vector<std::string> beerReg {
    "Kaljaa? Tottakai",
    "Kaljaa herralle, olkaa hyvä",
    "Kaikkien janoisten sankari",
    "Kyllä herra",
    "Tietysti pauligin",
    "Ei täällä kuivin suin olla"
};

} // namespace replies

} // namespace resources
} // namespace saunabot
