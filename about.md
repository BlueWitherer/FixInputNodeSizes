# ![🎛](frame:GJ_extendedIcon_001.png?scale=0.875) FixThoseDangInputNodes!
**Fix vanilla text input nodes' sizes.**

*by [Cheeseworks](user:6408873)!*

> ![✳️](frame:collaborationIcon_001.png) <cg>*This mod has settings you can utilize to customize your experience.*</c>

---

## About
A **lightweight mod to fix some sizing issues with RobTop's crazy `CCTextInputNode`s** across the game! Primarily intended for other mods that require use of said nodes. Allows for the user to toggle this fix for specific UI pages.

---

### Developers
If your mod <cr>critically depends on any of these fixes</c>, feel free to use this mod's API. Be sure to follow its [documentation](https://www.github.com/BlueWitherer/FixInputNodeSizes/tree/master/include/)!
```cpp
class $modify(FTDINEditLevelLayer, EditLevelLayer) {
    INPUTNODEFIX_HOOK_ALL(inputnodefix::layer::edit_level_layer);

    bool init(GJGameLevel* level) {
        if (!EditLevelLayer::init(level)) return false;

        // do stuff with the text input nodes

        return true;
    };
};
```
> ![⚠️](frame:geode.loader/info-warning.png?scale=0.375) <cy>*Text input nodes in editor UI aren't currently accounted for.*</c>

---

![🗨️](frame:gj_discordIcon_001.png?scale=0.375) **If you need help, join my [support Discord server](https://www.dsc.gg/cheeseworks) and ask! :)**