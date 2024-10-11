#include "Word.h"

#include <cstdio>
#include <cstring>

namespace
{
size_t maxSize = 30;
}

Word::Word()
{
    m_str = new char[1];
    *m_str = '\0';
}

Word::Word(const char* str)
{
    if (str)
    {
        auto strSize = strlen(str);
        if (strSize > maxSize)
            strSize = maxSize;

        m_str = new char[strSize + 1];

        for (size_t i = 0; i < strSize; ++i)
            m_str[i] = str[i];

        m_str[strSize] = '\0';
    }
    else
    {
        m_str = new char[1];
        *m_str = '\0';
    }

}

Word::Word(const Word& other)
{
    auto strSize = strlen(other.m_str);
    m_str = new char[strSize + 1];

    for (size_t i = 0; i < strSize; ++i)
        m_str[i] = other.m_str[i];

    m_str[strSize] = '\0';
}

Word::Word(Word&& other) noexcept
{
    m_str = other.m_str;
    other.m_str = nullptr;
}

Word::~Word()
{
    delete[] m_str;
}

Word& Word::operator=(const Word& other)
{
    if (this == &other)
        return *this;

    delete[] m_str;

    auto strSize = strlen(other.m_str);
    m_str = new char[strSize + 1];

    for (size_t i = 0; i < strSize; ++i)
        m_str[i] = other.m_str[i];

    m_str[strSize] = '\0';

    return *this;
}

Word& Word::operator=(Word&& other) noexcept
{
    if (this == &other)
        return *this;

    delete[] m_str;

    m_str = other.m_str;
    other.m_str = nullptr;

    return *this;
}

bool Word::operator==(const Word& other)
{
    return strcmp(m_str, other.m_str) == 0;
}

bool Word::operator>(const Word& other)
{
    return strcmp(m_str, other.m_str) > 0;
}

bool Word::operator<(const Word& other)
{
    return strcmp(m_str, other.m_str) < 0;
}

const char* Word::data() const
{
    return m_str;
}
