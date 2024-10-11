#pragma once

#include <string>

#include "AbstractFileExecutor.h"

class WordCounter : public AbstractFileExecutor
{
public:
    WordCounter(const std::string& fileName, const std::string& searchWord);

    void execute() override;

private:
    std::string m_searchWord;
};