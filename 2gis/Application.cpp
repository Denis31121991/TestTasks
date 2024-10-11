#include "Application.h"

#include <algorithm>
#include <array>
#include <exception>
#include <string>
#include <iostream>

#include "ChecksumProvider.h"
#include "Helper.h"
#include "WordCounter.h"

Application::Application(int argc, char* argv[])
    : m_cmdLineParser(argc, argv)
{
    const std::string fileTag = "f";
    const std::string modeTag = "m";
    const std::string wordTag = "v";
    const std::string helpTag = "h";
    const std::string checksumModeTag = "checksum";
    const std::string wordModeTag = "words";
    const std::array<const std::string, 4> optionTags {fileTag, modeTag, wordTag, helpTag};

    bool hasValidOption = std::any_of(optionTags.cbegin(), optionTags.cend(), [this](const auto& optionTag){
        return m_cmdLineParser.hasOption(optionTag);
    });

    try
    {
        if (!hasValidOption)
            throw std::runtime_error("No valid options!");

        if (m_cmdLineParser.hasOption(helpTag))
        {
            m_executor = IExecutor::create<Helper>();
            return;
        }
    
        if (m_cmdLineParser.hasOption(fileTag))
        {
            const std::string fileName = m_cmdLineParser.value(fileTag);

            if (fileName.empty())
                throw std::runtime_error("If you use a -f option, you should set a file name!");

            if (m_cmdLineParser.hasOption(modeTag))
            {
                const std::string modeValue = m_cmdLineParser.value(modeTag);

                if (modeValue.empty())
                    throw std::runtime_error("You should set a mode!");
                
                if (modeValue == wordModeTag)
                {
                    if (!m_cmdLineParser.hasOption(wordTag))
                        throw std::runtime_error("You should set a search word!");

                    const std::string searchWord = m_cmdLineParser.value(wordTag);

                    if (searchWord.empty())
                        throw std::runtime_error("You should set a search word!");
                        
                    m_executor = IExecutor::create<WordCounter>(fileName, searchWord);
                    return;
                }

                if (modeValue == checksumModeTag)
                {
                    m_executor = IExecutor::create<ChecksumProvider>(fileName);
                    return;
                }
            }
            else
            {
                throw std::runtime_error("You should set a mode!");
            }
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
        m_executor = IExecutor::create<Helper>();
    }
}

void Application::run()
{
    m_executor->execute();
}
