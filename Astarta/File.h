#pragma once

#include <cstdio>

class File
{
public:
    File(const char* fileName, const char* mode);
    ~File();

    int nextCharacter();

private:
    FILE* m_descriptor;
};