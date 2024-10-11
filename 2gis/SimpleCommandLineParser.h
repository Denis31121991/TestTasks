#pragma once

#include <string>
#include <unordered_map>

class SimpleCommandLineParser
{
public:
    SimpleCommandLineParser(int argc, char* argv[]);

    bool hasOption(const std::string& opt) const;

    std::string value(const std::string& opt) const noexcept;

private:
    std::unordered_map<std::string, std::string> m_options;
};