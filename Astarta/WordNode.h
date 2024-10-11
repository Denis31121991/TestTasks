#pragma once

#include "Word.h"

struct WordNode
{
    Word word;
    int count = 0;

    WordNode* next = nullptr;
};