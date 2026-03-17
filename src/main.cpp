#include <API.hpp>

#include <Geode/Geode.hpp>

#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/GJAccountSettingsLayer.hpp>
#include <Geode/modify/SecretLayer.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/modify/SecretLayer5.hpp>

using namespace geode::prelude;
using namespace inputnodefix;

$on_game(Loaded) {
    listenForSettingChanges<bool>(
        layer::edit_level_layer,
        [](bool value) {
            if (auto fm = FixManager::get()) fm->toggle(layer::edit_level_layer, value);
        });

    listenForSettingChanges<bool>(
        layer::level_search_layer,
        [](bool value) {
            if (auto fm = FixManager::get()) fm->toggle(layer::level_search_layer, value);
        });

    listenForSettingChanges<bool>(
        layer::account_settings_layer,
        [](bool value) {
            if (auto fm = FixManager::get()) fm->toggle(layer::account_settings_layer, value);
        });

    listenForSettingChanges<bool>(
        layer::secret_layers,
        [](bool value) {
            if (auto fm = FixManager::get()) fm->toggle(layer::secret_layers, value);
        });
};

class $modify(FTDINEditLevelLayer, EditLevelLayer) {
    FTDIN_HOOK_ALL(layer::edit_level_layer);

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
    FTDIN_HOOK_ALL(layer::level_search_layer);

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
    FTDIN_HOOK_ALL(layer::account_settings_layer);

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
    FTDIN_HOOK_ALL(layer::secret_layers);

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
    FTDIN_HOOK_ALL(layer::secret_layers);

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
    FTDIN_HOOK_ALL(layer::secret_layers);

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
    FTDIN_HOOK_ALL(layer::secret_layers);

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