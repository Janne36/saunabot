
#include "utils.hpp"

namespace saunabot {
namespace utils {

std::string ReadToken(const std::filesystem::path &path)
{
    std::ifstream in(path);
    if (!in)
    {
        throw "token file missing";
    }

    std::string str;
    std::getline(in, str);

    in.close();

    return str;
}

} // namespace utils
} // namespace saunabot
