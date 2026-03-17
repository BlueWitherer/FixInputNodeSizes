#include <API.hpp>

#include <Geode/Geode.hpp>

using namespace geode::prelude;
using namespace inputnodefix;

bool FixManager::isEnabledFor(std::string_view layer) const {
    return Mod::get()->getSettingValue<bool>(layer);
};

void FixManager::toggle(ZStringView layer, bool toggle) {
    for (auto& hook : m_hooks[layer]) {
        if (auto h = hook.lock()) (void)h->toggle(toggle);
    };
};

void FixManager::registerHook(std::weak_ptr<Hook> hook, ZStringView layer) {
    m_hooks[layer].push_back(hook);
};

FixManager* FixManager::get() noexcept {
    static auto inst = new (std::nothrow) FixManager();
    return inst;
};