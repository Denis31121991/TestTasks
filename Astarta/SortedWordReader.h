#pragma once

#include <cstdio>

#include "Enums.h"
#include "SortedWordList.h"

class File;

class SortedWordReader
{
public:
    SortedWordReader(File& file, SortOrder order);

    const SortedWordList& words() const;

private:
    SortedWordList m_sortedWordList;
};