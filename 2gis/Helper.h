#pragma once

#include "IExecutor.h"

class Helper : public IExecutor
{
public:
    void execute() override;
};