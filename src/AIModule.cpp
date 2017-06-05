#include <AIModule.h>
#include <BWAPI/AIModule.h>
#include "Cast.hpp"

class AIModuleWrapper : public BWAPI::AIModule
{
protected:
    ::AIModule* module;

public:
    virtual void onStart() override {
        module->vtable->onStart(module);
    }
    virtual void onEnd(bool isWinner) override {
        module->vtable->onEnd(module, isWinner);
    }
    virtual void onFrame() override {
        module->vtable->onFrame(module);
    }
    virtual void onSendText(std::string text) override {
        module->vtable->onSendText(module, text.c_str());
    }
    virtual void onReceiveText(BWAPI::Player player, std::string text) override {
        module->vtable->onReceiveText(module, reinterpret_cast<Player*>(player), text.c_str());
    }
    virtual void onPlayerLeft(BWAPI::Player player) override {
        module->vtable->onPlayerLeft(module, reinterpret_cast<Player*>(player));
    }
    virtual void onNukeDetect(BWAPI::Position target) override {
        module->vtable->onNukeDetect(module, cast_from_bw(target));
    }
    virtual void onUnitDiscover(BWAPI::Unit unit) override {
        module->vtable->onUnitDiscover(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitEvade(BWAPI::Unit unit) override {
        module->vtable->onUnitEvade(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitShow(BWAPI::Unit unit) override {
        module->vtable->onUnitShow(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitHide(BWAPI::Unit unit) override {
        module->vtable->onUnitHide(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitCreate(BWAPI::Unit unit) override {
        module->vtable->onUnitCreate(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitDestroy(BWAPI::Unit unit) override {
        module->vtable->onUnitDestroy(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitMorph(BWAPI::Unit unit) override {
        module->vtable->onUnitMorph(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitRenegade(BWAPI::Unit unit) override {
        module->vtable->onUnitRenegade(module, reinterpret_cast<Unit*>(unit));
    }
    virtual void onSaveGame(std::string gameName) override {
        module->vtable->onSaveGame(module, gameName.c_str());
    }
    virtual void onUnitComplete(BWAPI::Unit unit) override {
        module->vtable->onUnitComplete(module, reinterpret_cast<Unit*>(unit));
    }

    AIModuleWrapper(::AIModule* module)
        : module(module)
    {
    }
};

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule* module) {
    return reinterpret_cast<void*>( new AIModuleWrapper(module) );
}
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module) {
    delete reinterpret_cast<AIModuleWrapper*>(module);
}
