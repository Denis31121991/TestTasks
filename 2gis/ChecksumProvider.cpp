#include "ChecksumProvider.h"

#include <cstdint>
#include <iostream>

ChecksumProvider::ChecksumProvider(const std::string& fileName)
    : AbstractFileExecutor(fileName)
{
}

void ChecksumProvider::execute()
{
    uint32_t checksum = 0;
    uint32_t word = 0;
    char byte = 0;
    int byteCount = 0;

    while (m_file.get(byte))
    {
        word = (word << 8) | (static_cast<uint8_t>(byte));
        byteCount++;

        if (byteCount == 4)
        {
            checksum += word;
            checksum = checksum & 0xFFFFFFFF;
            word = 0;
            byteCount = 0;
        }
    }

    // Добавляем оставшиеся байты, если они есть
    if (byteCount > 0)
    {
        word <<= 8 * (4 - byteCount);
        checksum += word;
        checksum = checksum & 0xFFFFFFFF;
    }

    std::cout << "Checksum: " << checksum << std::endl;
}
