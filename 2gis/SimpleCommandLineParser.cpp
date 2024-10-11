#include "SimpleCommandLineParser.h"

SimpleCommandLineParser::SimpleCommandLineParser(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string key = argv[i] + 1;
        if (argv[i][0] == '-')
        {
            if (i + 1 < argc && argv[i + 1][0] != '-')
            {
                m_options[key] = argv[i + 1];
                ++i; // Пропустить значение, так как оно уже добавлено
            }
            else
            {
                m_options[key] = "";
            }
        }
    }
}

bool SimpleCommandLineParser::hasOption(const std::string& opt) const
{
    return m_options.find(opt) != m_options.cend();
}

std::string SimpleCommandLineParser::value(const std::string& opt) const noexcept
{
    const auto found = m_options.find(opt);
    if (found != m_options.cend())
        return found->second;
    return {};
}
