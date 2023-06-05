#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include <configparser.hpp>

namespace saunabot {
namespace utils {

std::string ReadToken(const std::filesystem::path& path);

template<typename T>
T PickRandom(const std::vector<T>& vec)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<unsigned int> uni(0, vec.size());
    const auto randomIndex = uni(rng);
    try {
        return vec.at(randomIndex);
    }
    catch (const std::out_of_range&) {
        // Fallback to first value in reply in case of failure
        // TODO: Loggging (and log failures)
        return vec.front();
    }
}

} // namespace utils
} // namespace saunabot
