#include "WordCounter.h"

#include <iostream>
#include <regex>

WordCounter::WordCounter(const std::string& fileName, const std::string& searchWord)
    : AbstractFileExecutor(fileName)
    , m_searchWord(searchWord)
{
}

void WordCounter::execute()
{
    long long countWord = 0;
    std::string line;
    std::regex wordRegex("\\b" + m_searchWord + "\\b");

    while (std::getline(m_file, line)) {
        auto wordsBegin = std::sregex_iterator(line.begin(), line.end(), wordRegex);
        auto wordsEnd = std::sregex_iterator();
        countWord += std::distance(wordsBegin, wordsEnd);
    }

    std::cout << "Count: " << countWord << std::endl;
}