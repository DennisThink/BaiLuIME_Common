
#include "Logger.h"

#include <iostream>

namespace BaiLu
{
    namespace
    {
        const char* GetLevelName(LogLevel level)
        {
            switch (level)
            {
            case LogLevel::Debug:
                return "DEBUG";

            case LogLevel::Info:
                return "INFO";

            case LogLevel::Warn:
                return "WARN";

            case LogLevel::Error:
                return "ERROR";

            case LogLevel::Critical:
                return "CRITICAL";

            default:
                return "UNKNOWN";
            }
        }
    }

    void ConsoleBackend::Write(
        LogLevel level,
        std::string_view message)
    {
        std::clog << '['
                  << GetLevelName(level)
                  << "] "
                  << message
                  << '\n';
    }

    Logger::Logger()
        : backend_(std::make_unique<ConsoleBackend>())
    {
    }

    Logger& Logger::Instance()
    {
        static Logger instance;
        return instance;
    }

    void Logger::SetBackend(
        std::unique_ptr<ILoggerBackend> backend)
    {
        if (!backend)
        {
            return;
        }

        std::lock_guard<std::mutex> lock(mutex_);
        backend_ = std::move(backend);
    }

    void Logger::Write(
        LogLevel level,
        std::string_view message)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (backend_)
        {
            backend_->Write(level, message);
        }
    }
}
