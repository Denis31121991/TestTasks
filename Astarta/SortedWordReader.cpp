#include "SortedWordReader.h"

#include <cstring>

#include "File.h"

#define IS_LOWERCASE(ch) (ch > 96 && ch < 123)

namespace
{
constexpr const int bufferSize = 30;
}

SortedWordReader::SortedWordReader(File& file, SortOrder order)
    : m_sortedWordList(order)
{
    int ch = 0;
    char buffer [bufferSize];
    
    for (int i = 0; i < bufferSize; ++i)
        buffer[i] = '\0';

    char* iter = buffer;
    bool startWord = false;

    while ((ch = file.nextCharacter()) != EOF)
    {
        if (!IS_LOWERCASE(ch))
        {
            if (!startWord)
                continue;

            *iter = '\0';
            m_sortedWordList.addOrIncrement(Word(buffer));
            iter = buffer;
            startWord = false;
            continue;
        }

        startWord = true;
        *iter = ch;
        iter++;
    }

    if (startWord)
    {
        *iter = '\0';
        m_sortedWordList.addOrIncrement(Word(buffer));
        iter = buffer;
        startWord = false;
    }
}

const SortedWordList& SortedWordReader::words() const
{
    return m_sortedWordList;
}