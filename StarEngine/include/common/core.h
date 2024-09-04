#pragma once
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <sstream>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>

#define FMT_HEADER_ONLY
#define SPDLOG_FMT_EXTERNAL

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

// import, export
#ifdef STAR_EXPORT
#ifdef _MSC_VER
#define STAR_API __declspec(dllexport)
#else
#define STAR_API __attribute__((visibility("default")))
#endif
#else
#ifdef _MSC_VER
#define STAR_API __declspec(dllimport)
#else
#define STAR_API
#endif
#endif

// runtime assertion
#define STAR_ASSERT assert

// compile-time assertion
#if defined(__clang__) || defined(__GNUC__)
#define STAR_STATIC_ASSERT _Static_assert
#else
#define STAR_STATIC_ASSERT static_assert
#endif

// function inlining
#if defined(__clang__) || defined(__GNUC__)
#define STAR_INLINE __attribute__((always_inline)) inline
#define STAR_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
#define STAR_INLINE __forceinline
#define STAR_NOINLINE __declspec(noinline)
#else
#define STAR_INLINE inline
#define STAR_NOINLINE
#endif

// core features
namespace Star
{
    // runtime type
    template <typename T>
    STAR_INLINE constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }

    // console logging
    struct STAR_API Logger
    {
        using SPDLog = std::shared_ptr<spdlog::logger>;

        STAR_INLINE Logger()
        {
            m_SPD = spdlog::stdout_color_mt("stdout");
            m_SPD->set_level(spdlog::level::trace);
            m_SPD->set_pattern("%^[%T]: [%t] %v%$");
        }

        STAR_INLINE static SPDLog& Ref()
        {
            static Logger logger;
            return logger.m_SPD;
        }

    private:
        SPDLog m_SPD;
    };

    // logging macros
#ifdef STAR_ENABLE_LOG
#define STAR_TRACE(...) Star::Logger::Ref()->trace(__VA_ARGS__)
#define STAR_DEBUG(...) Star::Logger::Ref()->debug(__VA_ARGS__)
#define STAR_INFO(...) Star::Logger::Ref()->info(__VA_ARGS__)
#define STAR_WARN(...) Star::Logger::Ref()->warn(__VA_ARGS__)
#define STAR_ERROR(...) Star::Logger::Ref()->error(__VA_ARGS__)
#define STAR_FATAL(...) Star::Logger::Ref()->critical(__VA_ARGS__)
#else
#define STAR_TRACE(...)
#define STAR_DEBUG(...)
#define STAR_INFO(...)
#define STAR_WARN(...)
#define STAR_ERROR(...)
#define STAR_FATAL(...)
#endif

    // free allocated memory
#define STAR_DELETE(ptr) \
    if (ptr != nullptr)  \
    {                    \
        delete (ptr);    \
        ptr = nullptr;   \
    }

} // namespace Star
