#include <API.hpp>

#include <Geode/Geode.hpp>

using namespace geode::prelude;
using namespace inputnodefix;

bool FixManager::isHookRegistered(std::weak_ptr<Hook> const& hook, ZStringView layer) const noexcept {
    if (auto const h = hook.lock()) {
        auto const hookVector = m_hooks.find(layer);
        if (hookVector == m_hooks.end()) return false;

        for (auto const& regHook : hookVector->second) {
            if (auto const reg = regHook.lock()) {
                if (reg == h) return true;
            };
        };
    };

    return false;
};

bool FixManager::isEnabledFor(std::string_view layer) const {
    return Mod::get()->getSettingValue<bool>(layer);
};

void FixManager::toggle(ZStringView layer, bool toggle) {
    for (auto const& hook : m_hooks[layer]) {
        if (auto h = hook.lock()) (void)h->toggle(toggle);
    };
};

void FixManager::registerHook(std::weak_ptr<Hook> hook, ZStringView layer) {
    if (!isHookRegistered(hook, layer)) m_hooks[layer].push_back(std::move(hook));
};

FixManager* FixManager::get() noexcept {
    static auto inst = new (std::nothrow) FixManager();
    return inst;
};