#pragma once

#include <string>

#include "AbstractFileExecutor.h"

class ChecksumProvider : public AbstractFileExecutor
{
public:
    ChecksumProvider(const std::string& fileName);

    void execute() override;
};