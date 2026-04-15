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

#include <Geode/utils/StringMap.hpp>
#include <Geode/utils/ZStringView.hpp>

#include <Geode/loader/Hook.hpp>

// Container for FixThoseDangInputNodes! API
namespace inputnodefix {
    namespace layer {
        inline constexpr auto edit_level_layer = "edit-level-layer";
        inline constexpr auto level_search_layer = "level-search-layer";
        inline constexpr auto more_options_layer = "more-options-layer";
        inline constexpr auto share_comment_layer = "share-comment-layer";
        inline constexpr auto write_message_popup = "write-message-popup";
        inline constexpr auto account_settings_layer = "account-settings-layer";
        inline constexpr auto account_login_layer = "account-login-layer";
        inline constexpr auto secret_layers = "secret-layers";
    };

    class CW_FIXINPUTNODES_API_DLL FixManager final {
    private:
        geode::utils::StringMap<std::vector<std::weak_ptr<geode::Hook>>> m_hooks;  // Map of registered hooks

    protected:
        // Check if a hook has already been registered
        bool isHookRegistered(std::weak_ptr<geode::Hook> const& hook, geode::ZStringView layer) const noexcept;

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

#ifdef INPUTNODEFIX_INTERNAL  // Do NOT define if using API from external mod!
#define INPUTNODEFIX_HOOK_PRIORITY(hook)                                       \
    (void)self.setHookPriorityPre(hook->getDisplayName(), Priority::FirstPre); \
    log::trace("Hook priority for '{}' set to highest", hook->getDisplayName())
#else
#define INPUTNODEFIX_HOOK_PRIORITY(hook)
#endif

#define INPUTNODEFIX_HOOK_ALL(settingId)                                                 \
    static void onModify(auto& self) {                                                   \
        if (auto fm = inputnodefix::FixManager::get()) {                                 \
            geode::utils::StringMap<std::shared_ptr<geode::Hook>>& hooks = self.m_hooks; \
            auto enable = fm->isEnabledFor(settingId);                                   \
                                                                                         \
            for (auto& hook : hooks | std::views::values) {                              \
                INPUTNODEFIX_HOOK_PRIORITY(hook);                                        \
                                                                                         \
                hook->setAutoEnable(enable);                                             \
                (void)hook->toggle(enable);                                              \
                                                                                         \
                fm->registerHook(hook, settingId);                                       \
            };                                                                           \
        };                                                                               \
    }