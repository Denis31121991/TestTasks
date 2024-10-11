#include "AbstractFileExecutor.h"

#include <exception>

AbstractFileExecutor::AbstractFileExecutor(const std::string& fileName)
{
    m_file.open(fileName);
    if (!m_file.is_open())
        throw std::runtime_error("Cannot open file: " + fileName);
}

AbstractFileExecutor::~AbstractFileExecutor()
{
    m_file.close();
}