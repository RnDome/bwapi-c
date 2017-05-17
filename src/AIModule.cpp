#include <AIModule.h>
#include <BWAPI/AIModule.h>

#include "Position.hpp"

#include <memory>
#include <cstring>

class AIModuleWrapper : public BWAPI::AIModule
{
protected:
    std::unique_ptr<::AIModule, decltype(&std::free)> module;

public:
    virtual void onStart() override {
        module->vtable->onStart(module.get());
    }
    virtual void onEnd(bool isWinner) override {
        module->vtable->onEnd(module.get(), isWinner);
    }
    virtual void onFrame() override {
        module->vtable->onFrame(module.get());
    }
    virtual void onSendText(std::string text) override {
        module->vtable->onSendText(module.get(), text.c_str());
    }
    virtual void onReceiveText(BWAPI::Player player, std::string text) override {
        module->vtable->onReceiveText(module.get(), reinterpret_cast<Player*>(player), text.c_str());
    }
    virtual void onPlayerLeft(BWAPI::Player player) override {
        module->vtable->onPlayerLeft(module.get(), reinterpret_cast<Player*>(player));
    }
    virtual void onNukeDetect(BWAPI::Position target) override {
        module->vtable->onNukeDetect(module.get(), position_from_bw(target));
    }
    virtual void onUnitDiscover(BWAPI::Unit unit) override {
        module->vtable->onUnitDiscover(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitEvade(BWAPI::Unit unit) override {
        module->vtable->onUnitEvade(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitShow(BWAPI::Unit unit) override {
        module->vtable->onUnitShow(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitHide(BWAPI::Unit unit) override {
        module->vtable->onUnitHide(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitCreate(BWAPI::Unit unit) override {
        module->vtable->onUnitCreate(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitDestroy(BWAPI::Unit unit) override {
        module->vtable->onUnitDestroy(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitMorph(BWAPI::Unit unit) override {
        module->vtable->onUnitMorph(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onUnitRenegade(BWAPI::Unit unit) override {
        module->vtable->onUnitRenegade(module.get(), reinterpret_cast<Unit*>(unit));
    }
    virtual void onSaveGame(std::string gameName) override {
        module->vtable->onSaveGame(module.get(), gameName.c_str());
    }
    virtual void onUnitComplete(BWAPI::Unit unit) override {
        module->vtable->onUnitComplete(module.get(), reinterpret_cast<Unit*>(unit));
    }

    AIModuleWrapper(::AIModule* module_, size_t module_size)
        : module(nullptr, &std::free)
    {
        ::AIModule* buff = reinterpret_cast<::AIModule*>( std::malloc(module_size) );
        std::memmove(buff, module_, module_size);
        module.reset(buff);
    }
};

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule* module, size_t module_size) {
    return reinterpret_cast<void*>( new AIModuleWrapper(module, module_size) );
}
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module) {
    delete reinterpret_cast<AIModuleWrapper*>(module);
}
