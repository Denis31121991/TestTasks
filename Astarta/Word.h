#pragma once

class Word
{
public:
    Word();
    Word(const char* str);
    Word(const Word& other);
    Word(Word&& other) noexcept;

    ~Word();

    Word& operator=(const Word& other);
    Word& operator=(Word&& other) noexcept;

    bool operator==(const Word& other);

    bool operator>(const Word& other);
    bool operator<(const Word& other);

    const char* data() const;

private:
    char* m_str;
};