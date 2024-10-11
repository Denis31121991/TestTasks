#pragma once

#include <memory>

#include "SimpleCommandLineParser.h"

#include "IExecutor.h"

class Application
{
public:
    Application(int argc, char* argv[]);

    void run();

private:
    SimpleCommandLineParser m_cmdLineParser;
    std::unique_ptr<IExecutor> m_executor;
};