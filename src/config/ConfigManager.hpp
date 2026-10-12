#pragma once

#include <abyssutils/animation/AnimationConfig.hpp>

#include <abyssparse.hpp>
#include <optional>
#include <expected>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "../defines.hpp"

class CConfigManager {
  public:
    static std::expected<std::string, std::string> resolveConfigPath(std::optional<std::string_view> explicitPath);
    CConfigManager(const char* configPath);
    void init();

    template <typename T>
    Abyssparse::CSimpleConfigValue<T> getValue(const std::string& name) {
        return Abyssparse::CSimpleConfigValue<T>(&m_config, name.c_str());
    }

    struct SWidgetConfig {
        std::string                               type;
        std::string                               monitor;

        std::unordered_map<std::string, std::any> values;
    };

    std::vector<SWidgetConfig>                 getWidgetConfigs();

    std::optional<std::string>                 handleSource(const std::string&, const std::string&);
    std::optional<std::string>                 handleBezier(const std::string&, const std::string&);
    std::optional<std::string>                 handleAnimation(const std::string&, const std::string&);

    std::string                                m_configCurrentPath;

    Abyssutils::Animation::CAnimationConfigTree m_AnimationTree;

  private:
    Abyssparse::CConfig m_config;
};

inline UP<CConfigManager> g_pConfigManager;
