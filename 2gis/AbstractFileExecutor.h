#pragma once

#include <fstream>
#include <string>

#include "IExecutor.h"

class AbstractFileExecutor : public IExecutor
{
public:
    AbstractFileExecutor(const std::string& fileName);

    ~AbstractFileExecutor();


protected:
    std::ifstream m_file;
    
};