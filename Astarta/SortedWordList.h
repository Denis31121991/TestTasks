#pragma once

#include "Enums.h"
#include "WordNode.h"

#include <utility>

class SortedWordList
{
public:
    SortedWordList(SortOrder order);
    ~SortedWordList();

    SortedWordList(const SortedWordList& other) = delete;
    SortedWordList(SortedWordList&& other) = delete;

    SortedWordList& operator=(const SortedWordList& other) = delete;
    SortedWordList& operator=(SortedWordList&& other) = delete;

    template<typename T>
    void addOrIncrement(T&& node);

    void print() const;

private:
    template<typename T>
    WordNode* createWordNode(T&& word) const;

private:
    WordNode* m_head;
    SortOrder m_order;
};


template<typename T>
void SortedWordList::addOrIncrement(T&& word)
{
    WordNode** next = &m_head;

    while (*next)
    {
        if ((*next)->word == word)
        {
            (*next)->count++;
            return;
        }
        else
        {
            if (m_order == SortOrder::Ascending)
            {
                if ((*next)->word > word)
                    break;
            }
            else if (m_order == SortOrder::Descending)
            {
                if ((*next)->word < word)
                    break;
            }
        }

        next = &(*next)->next;
    }

    //auto node = createWordNode(std::forward<T>(word));
    auto node = createWordNode(word);
    node->next = *next;
    *next = node;
}

template<typename T>
WordNode* SortedWordList::createWordNode(T&& word) const
{
    WordNode* node = new WordNode;
    //node->word = std::forward<T>(word);
    node->word = word;
    node->count = 1;
    return node;
}
