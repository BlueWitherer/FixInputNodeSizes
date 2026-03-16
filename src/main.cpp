#include <ranges>

#include <Geode/Geode.hpp>

#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/GJAccountSettingsLayer.hpp>
#include <Geode/modify/SecretLayer.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/modify/SecretLayer5.hpp>

using namespace geode::prelude;

namespace settings {
    constexpr auto edit_level_layer = "edit-level-layer";
    constexpr auto level_search_layer = "level-search-layer";
    constexpr auto account_settings_layer = "account-settings-layer";
    constexpr auto secret_layers = "secret-layers";
};

auto& sHooks() {  // lazy init for hooks map (thanks android)
    static std::unordered_map<std::string, std::vector<std::weak_ptr<Hook>>> s_hooks;
    return s_hooks;
};

#define FTDIN_HOOK_ALL(settingId)                                                      \
    static void onModify(auto& self) {                                                 \
        utils::StringMap<std::shared_ptr<Hook>>& hooks = self.m_hooks;                 \
        auto enable = Mod::get()->getSettingValue<bool>(settingId);                    \
                                                                                       \
        for (auto& hook : hooks | std::views::values) {                                \
            (void)self.setHookPriorityPre(hook->getDisplayName(), Priority::FirstPre); \
                                                                                       \
            hook->setAutoEnable(enable);                                               \
            (void)hook->toggle(enable);                                                \
                                                                                       \
            sHooks()[settingId].push_back(hook);                                       \
        };                                                                             \
    }

#define FTDIN_TOGGLE_HOOKS(settingId)                     \
    for (auto& hook : sHooks()[settingId]) {              \
        if (auto h = hook.lock()) (void)h->toggle(value); \
    }

$on_mod(Loaded) {
    listenForSettingChanges<bool>(
        settings::edit_level_layer,
        [](bool value) {
            FTDIN_TOGGLE_HOOKS(settings::edit_level_layer);
        });

    listenForSettingChanges<bool>(
        settings::level_search_layer,
        [](bool value) {
            FTDIN_TOGGLE_HOOKS(settings::level_search_layer);
        });

    listenForSettingChanges<bool>(
        settings::account_settings_layer,
        [](bool value) {
            FTDIN_TOGGLE_HOOKS(settings::account_settings_layer);
        });

    listenForSettingChanges<bool>(
        settings::secret_layers,
        [](bool value) {
            FTDIN_TOGGLE_HOOKS(settings::secret_layers);
        });
};

class $modify(FTDINEditLevelLayer, EditLevelLayer) {
    FTDIN_HOOK_ALL(settings::edit_level_layer);

    bool init(GJGameLevel* level) {
        if (!EditLevelLayer::init(level)) return false;

        if (auto name = getChildByID("level-name-input")) {
            log::trace("node {} found", name->getID());

            if (auto nameBg = getChildByID("level-name-background")) {
                name->setContentSize({
                    nameBg->getScaledContentWidth() - 8.75f,
                    nameBg->getScaledContentHeight(),
                });
            };
        };

        if (auto desc = getChildByID("description-input")) {
            log::trace("node {} found", desc->getID());

            if (auto descBg = getChildByID("description-background")) {
                desc->setContentSize({
                    descBg->getScaledContentWidth() - 8.75f,
                    descBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};

class $modify(FTDINLevelSearchLayer, LevelSearchLayer) {
    FTDIN_HOOK_ALL(settings::level_search_layer);

    bool init(int type) {
        if (!LevelSearchLayer::init(type)) return false;

        if (auto search = getChildByID("search-bar")) {
            log::trace("node {} found", search->getID());

            if (auto searchBg = getChildByID("level-search-bar-bg")) {
                search->setContentSize({
                    searchBg->getScaledContentWidth() - 7.5f,
                    searchBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};

class $modify(FTDINGJAccountSettingsLayer, GJAccountSettingsLayer) {
    FTDIN_HOOK_ALL(settings::account_settings_layer);

    bool init(int accountID) {
        if (!GJAccountSettingsLayer::init(accountID)) return false;

        for (int i = 0; i < 7; i++) {
            if (auto input = m_mainLayer->getChildByTag(i)) {
                log::trace("node {} found", input->getID());

                input->setContentWidth(input->getScaledContentWidth() - 2.5f);
                input->setPositionY(input->getPositionY() - 1.f);
            };
        };

        return true;
    };
};

class $modify(FTDINSecretLayer, SecretLayer) {
    FTDIN_HOOK_ALL(settings::secret_layers);

    bool init() {
        if (!SecretLayer::init()) return false;

        if (auto box = getChildByID("text-box")) {
            log::trace("node {} found", box->getID());

            if (auto boxBg = getChildByID("textbox-background")) {
                box->setContentSize({
                    boxBg->getScaledContentWidth() - 5.f,
                    boxBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};

class $modify(FTDINSecretLayer2, SecretLayer2) {
    FTDIN_HOOK_ALL(settings::secret_layers);

    bool init() {
        if (!SecretLayer2::init()) return false;

        if (auto box = getChildByID("text-box")) {
            log::trace("node {} found", box->getID());

            if (auto boxBg = getChildByID("textbox-background")) {
                box->setContentSize({
                    boxBg->getScaledContentWidth() - 5.f,
                    boxBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};

class $modify(FTDINSecretLayer4, SecretLayer4) {
    FTDIN_HOOK_ALL(settings::secret_layers);

    bool init() {
        if (!SecretLayer4::init()) return false;

        if (auto box = getChildByID("text-box")) {
            log::trace("node {} found", box->getID());

            if (auto boxBg = getChildByID("textbox-background")) {
                box->setContentSize({
                    boxBg->getScaledContentWidth() - 5.f,
                    boxBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};

class $modify(FTDINSecretLayer5, SecretLayer5) {
    FTDIN_HOOK_ALL(settings::secret_layers);

    bool init() {
        if (!SecretLayer5::init()) return false;

        if (auto box = getChildByID("text-box")) {
            log::trace("node {} found", box->getID());

            if (auto boxBg = getChildByID("textbox-background")) {
                box->setContentSize({
                    boxBg->getScaledContentWidth() - 5.f,
                    boxBg->getScaledContentHeight(),
                });
            };
        };

        return true;
    };
};