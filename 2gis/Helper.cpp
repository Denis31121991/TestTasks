#include "Helper.h"

#include <iostream>

void Helper::execute()
{
    std::cout << "-f <input_file> -m words -v <search_word> print a count of a words <search_word> in file\n"
              << "-f <input_file> -m checksum print 32-bit checksum, calculated by the algorithm checksum = word1 + word2 + ... + wordN (word1..wordN 32-bit words from file)\n"
              << "-h print help" << std::endl;
}