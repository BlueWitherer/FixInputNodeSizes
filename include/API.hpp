#pragma once

#ifdef GEODE_IS_WINDOWS
#ifdef CW_FIXINPUTNODES_API_EXPORTING
#define CW_FIXINPUTNODES_API_DLL __declspec(dllexport)
#else
#define CW_FIXINPUTNODES_API_DLL __declspec(dllimport)
#endif
#else
#ifdef CW_FIXINPUTNODES_API_EXPORTING
#define CW_FIXINPUTNODES_API_DLL __attribute__((visibility("default")))
#else
#define CW_FIXINPUTNODES_API_DLL
#endif
#endif

#include <ranges>

#include <Geode/utils/ZStringView.hpp>

#include <Geode/loader/Hook.hpp>

// Container for FixThoseDangInputNodes! API
namespace inputnodefix {
    namespace layer {
        inline constexpr auto edit_level_layer = "edit-level-layer";
        inline constexpr auto level_search_layer = "level-search-layer";
        inline constexpr auto account_settings_layer = "account-settings-layer";
        inline constexpr auto secret_layers = "secret-layers";
    };

    class CW_FIXINPUTNODES_API_DLL FixManager final {
    private:
        std::unordered_map<std::string, std::vector<std::weak_ptr<geode::Hook>>> m_hooks;  // Map of registered hooks

    public:
        // Get the FixManager singleton
        static FixManager* get() noexcept;

        /// Check if hooks should be enabled for a specific layer
        /// @param layer Setting ID for the layer (check `inputnodefix::layer`)
        /// @returns Whether these hooks should be enabled
        [[nodiscard]] bool isEnabledFor(std::string_view layer) const;

        /// Toggle all hooks registered for a specific layer
        /// @param layer Setting ID for the layer (check `inputnodefix::layer`)
        /// @param enabled Whether to toggle on or off
        void toggle(geode::ZStringView layer, bool enabled);

        /// Register a hook from your modified class for a specific layer
        /// @param hook A shared pointer to the hook
        /// @param layer Setting ID for the layer (check `inputnodefix::layer`)
        void registerHook(std::weak_ptr<geode::Hook> hook, geode::ZStringView layer);
    };
};

#define FTDIN_HOOK_ALL(settingId)                                                        \
    static void onModify(auto& self) {                                                   \
        if (auto fm = inputnodefix::FixManager::get()) {                                 \
            geode::utils::StringMap<std::shared_ptr<geode::Hook>>& hooks = self.m_hooks; \
            auto enable = fm->isEnabledFor(settingId);                                   \
                                                                                         \
            for (auto& hook : hooks | std::views::values) {                              \
                hook->setAutoEnable(enable);                                             \
                (void)hook->toggle(enable);                                              \
                                                                                         \
                fm->registerHook(hook, settingId);                                       \
            };                                                                           \
        };                                                                               \
    }