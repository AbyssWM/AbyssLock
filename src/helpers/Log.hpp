#pragma once
#include "../defines.hpp"

#include <format>
#include <print>
#include <abyssutils/cli/Logger.hpp>

#define RASSERT(expr, reason, ...)                                                                                                                                                 \
    if (!(expr)) {                                                                                                                                                                 \
        Log::logger->log(Log::CRIT, "\n==========================================================================================\nASSERTION FAILED! \n\n{}\n\nat: line {} in {}", \
                         std::format(reason, ##__VA_ARGS__), __LINE__,                                                                                                             \
                         ([]() constexpr -> std::string { return std::string(__FILE__).substr(std::string(__FILE__).find_last_of('/') + 1); })().c_str());                         \
        std::abort();                                                                                                                                                              \
    }

#define ASSERT(expr) RASSERT(expr, "?")

namespace Log {
    class CLogger {
      public:
        template <typename... Args>
        void log(Abyssutils::CLI::eLogLevel level, std::format_string<Args...> fmt, Args&&... args) {
            if (m_quiet)
                return;

            if (level == Abyssutils::CLI::LOG_TRACE && !m_verbose)
                return;

            m_logger.log(level, std::vformat(fmt.get(), std::make_format_args(args...)));
        }

        void setVerbose() {
            m_verbose = true;
            m_logger.setLogLevel(Abyssutils::CLI::LOG_TRACE);
        }

        void setQuiet() {
            m_quiet = true;
        }

        bool verbose() {
            return m_verbose;
        }

      private:
        bool                    m_quiet   = false;
        bool                    m_verbose = false;

        Abyssutils::CLI::CLogger m_logger;
    };

    inline UP<CLogger> logger = makeUnique<CLogger>();

    //
    inline constexpr const Abyssutils::CLI::eLogLevel WARN  = Abyssutils::CLI::LOG_WARN;
    inline constexpr const Abyssutils::CLI::eLogLevel ERR   = Abyssutils::CLI::LOG_ERR;
    inline constexpr const Abyssutils::CLI::eLogLevel CRIT  = Abyssutils::CLI::LOG_CRIT;
    inline constexpr const Abyssutils::CLI::eLogLevel INFO  = Abyssutils::CLI::LOG_DEBUG;
    inline constexpr const Abyssutils::CLI::eLogLevel TRACE = Abyssutils::CLI::LOG_TRACE;
};
