#include <AIModule.h>
#include <BWAPI/AIModule.h>

#include "Position.hpp"

class AIModuleWrapper : public BWAPI::AIModule
{
protected:
    ::AIModule module;

public:
    virtual void onStart() {
        module.onStart(&module);
    }
    virtual void onEnd(bool isWinner) {
        module.onEnd(&module, isWinner);
    }
    virtual void onFrame() {
        module.onFrame(&module);
    }
    virtual void onSendText(std::string text) {
        module.onSendText(&module, text.c_str());
    }
    virtual void onReceiveText(BWAPI::Player player, std::string text) {
        module.onReceiveText(&module, reinterpret_cast<Player*>(player), text.c_str());
    }
    virtual void onPlayerLeft(BWAPI::Player player) {
        module.onPlayerLeft(&module, reinterpret_cast<Player*>(player));
    }
    virtual void onNukeDetect(BWAPI::Position target) {
        module.onNukeDetect(&module, position_from_bw(target));
    }
    virtual void onUnitDiscover(BWAPI::Unit unit) {
        module.onUnitDiscover(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitEvade(BWAPI::Unit unit) {
        module.onUnitEvade(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitShow(BWAPI::Unit unit) {
        module.onUnitShow(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitHide(BWAPI::Unit unit) {
        module.onUnitHide(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitCreate(BWAPI::Unit unit) {
        module.onUnitCreate(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitDestroy(BWAPI::Unit unit) {
        module.onUnitDestroy(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitMorph(BWAPI::Unit unit) {
        module.onUnitMorph(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitRenegade(BWAPI::Unit unit) {
        module.onUnitRenegade(&module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onSaveGame(std::string gameName) {
        module.onSaveGame(&module, gameName.c_str());
    }
    virtual void onUnitComplete(BWAPI::Unit unit) {
        module.onUnitComplete(&module, reinterpret_cast<Unit*>(unit));
    }

    AIModuleWrapper(::AIModule module_) : module(module_) {}
};

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule module) {
    return reinterpret_cast<void*>( new AIModuleWrapper(module) );
}
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module) {
    delete reinterpret_cast<AIModuleWrapper*>(module);
}
