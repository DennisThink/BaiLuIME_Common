
#pragma once

#include <format>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <utility>

namespace BaiLu
{
    enum class LogLevel
    {
        Debug,
        Info,
        Warn,
        Error,
        Critical
    };

    // 日志后端接口：负责实际输出
    class ILoggerBackend
    {
    public:
        virtual ~ILoggerBackend() = default;

        virtual void Write(
            LogLevel level,
            std::string_view message) = 0;
    };

    // 默认控制台输出
    class ConsoleBackend final : public ILoggerBackend
    {
    public:
        void Write(
            LogLevel level,
            std::string_view message) override;
    };

    class Logger final
    {
    public:
        static Logger& Instance();

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        // 替换日志后端
        void SetBackend(
            std::unique_ptr<ILoggerBackend> backend);

        // 日志级别接口
        template<typename... Args>
        void Debug(
            std::format_string<Args...> format,
            Args&&... args)
        {
            Log(LogLevel::Debug, format,
                std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Info(
            std::format_string<Args...> format,
            Args&&... args)
        {
            Log(LogLevel::Info, format,
                std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Warn(
            std::format_string<Args...> format,
            Args&&... args)
        {
            Log(LogLevel::Warn, format,
                std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Error(
            std::format_string<Args...> format,
            Args&&... args)
        {
            Log(LogLevel::Error, format,
                std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Critical(
            std::format_string<Args...> format,
            Args&&... args)
        {
            Log(LogLevel::Critical, format,
                std::forward<Args>(args)...);
        }

    private:
        Logger();

        template<typename... Args>
        void Log(
            LogLevel level,
            std::format_string<Args...> format,
            Args&&... args)
        {
            std::string message = std::format(
                format,
                std::forward<Args>(args)...);

            Write(level, message);
        }

        void Write(
            LogLevel level,
            std::string_view message);

        std::unique_ptr<ILoggerBackend> backend_;
        std::mutex mutex_;
    };
}
