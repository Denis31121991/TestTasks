#include "File.h"

File::File(const char* fileName, const char* mode)
{
    m_descriptor = std::fopen(fileName, mode);

    if (!m_descriptor)
        throw "Can't open file";
}

File::~File()
{
    std::fclose(m_descriptor);
}

int File::nextCharacter()
{
    return std::fgetc(m_descriptor);
}
