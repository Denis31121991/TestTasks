#include "SortedWordList.h"

#include <cstdio>
#include <utility>

SortedWordList::SortedWordList(SortOrder order)
    : m_head {nullptr}
    , m_order(order)
{
}

SortedWordList::~SortedWordList()
{
    while (m_head)
    {
        WordNode* temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
}

void SortedWordList::print() const
{
    WordNode* iter = m_head;
    while (iter)
    {
        std::printf("%s - %d\n", iter->word.data(), iter->count);
        iter = iter->next;
    }
}