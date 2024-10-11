#pragma once

#include <memory>

class IExecutor
{
public:
    enum class Mode
    {
        Unknown,
        Checksum,
        WordCount,
        Help,
    };

public:
    virtual ~IExecutor() = default;

    virtual void execute() = 0;

    template<typename T, typename... Args>
    static std::unique_ptr<IExecutor> create(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
};