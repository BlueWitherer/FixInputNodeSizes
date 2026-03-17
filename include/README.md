# [<img src="../logo.png" width="25" alt="The mod's logo." />](https://www.geode-sdk.org/mods/cheeseworks.fixinputnodesizes) FixThoseDangInputNodes!
Fix vanilla text input nodes' sizes.

## Development
Let's start off by adding this mod as a dependency in your `mod.json`!
```jsonc
"dependencies": {
    "cheeseworks.fixinputnodesizes": ">=1.0.0"
}
```

You can directly access the Mod Developer Branding optional API by including the [`API.hpp`](API.hpp) file in your code.
```cpp
#include <cheeseworks.fixinputnodesizes/include/API.hpp>
```

### Hooking
If your hooks depend on this mod fixing vanilla text input nodes in that specific layer, here's how you can make them depend on this mod's settings for those hook to be enabled. This will register your hooks into this mod's hook manager and toggle them respectively in case the end user changes the settings on this mod.

The process of delegating your hooks to this mod can be simplified into one macro.
```cpp
FTDIN_HOOK_ALL(settingId);
```

> [!NOTE]
> The `settingId` parameter expects a string provided by the **`inputnodefix::layer`** namespace. Use the string that belongs to the name of the layer you hook.

You can call this macro under any modified layer class as shown here.
```cpp
class $modify(FTDINEditLevelLayer, EditLevelLayer) {
    FTDIN_HOOK_ALL(inputnodefix::layer::edit_level_layer);

    bool init(GJGameLevel* level) {
        if (!EditLevelLayer::init(level)) return false;

        // do stuff with the text input nodes

        return true;
    };
};
```
This will expand into a `static void onModify(auto& self)` that handles hook registration for you.

If done properly, your hooks will now only fire when the mod setting for the layer they hook is enabled.

*Happy modding!*