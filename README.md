# [<img src="logo.png" width="25" alt="The mod's logo." />](https://geode-sdk.org/mods/cheeseworks.fixinputnodesizes) FixThoseDangInputNodes!
Fix vanilla text input nodes' sizes.

> [![YouTube](https://img.shields.io/youtube/channel/subscribers/UCi2M6N_ff1UC6MyfWzKQvgg?style=for-the-badge&logo=youtube&logoColor=ffffff&label=YouTube)](https://www.youtube.com/@cheese_works/) [![Bluesky](https://img.shields.io/bluesky/followers/cheeseworks.gay?style=for-the-badge&logo=bluesky&logoColor=ffffff&label=Bluesky)](https://bsky.app/profile/cheeseworks.gay) [![Discord](https://img.shields.io/discord/734050209591459950?style=for-the-badge&logo=discord&logoColor=ffffff&label=Discord)](https://dsc.gg/cheeseworks)

> [![Version](https://img.shields.io/github/v/release/BlueWitherer/FixInputNodeSizes?include_prereleases&sort=semver&display_name=release&style=for-the-badge&logo=github&logoColor=ffffff&label=Version)](../../releases/) [![License](https://img.shields.io/github/license/BlueWitherer/FixInputNodeSizes?style=for-the-badge&logo=gnu&logoColor=ffffff&label=License)](LICENSE.md)
>  
> [![Downloads](https://img.shields.io/github/downloads/BlueWitherer/FixInputNodeSizes/total?style=for-the-badge&logo=geode&logoColor=ffffff&label=Downloads)](https://geode-sdk.org/mods/cheeseworks.fixinputnodesizes)

> [!TIP]
> *This mod has settings you can utilize to customize your experience.*

---

## About
A **lightweight mod to simply fix some sizing issues with RobTop's crazy `CCTextInputNode`s** across the game! Primarily intended for other mods that require use of said nodes. Allows for the user to toggle this fix for specific UI pages.

---

### Developers
If your mod critically depends on any of these fixes, feel free to use this mod's API. Be sure to follow its [documentation](./include/)!
```cpp
class $modify(FTDINEditLevelLayer, EditLevelLayer) {
    INPUTNODEFIX_HOOK_ALL(inputnodefix::layer::edit_level_layer);

    bool init(GJGameLevel* level) {
        if (!EditLevelLayer::init(level)) return false;

        // do stuff with those text input nodes

        return true;
    };
};
```
> [!WARNING]
> *Text input nodes in editor UI aren't currently accounted for.*

---

![preview](previews/preview-1.png)

---

### Changelog
###### What's new?!
**[📜 View the latest updates and patches](./changelog.md)**

### Issues
###### What's wrong?!
**[⚠️ Report a problem with the mod](../../issues/)**