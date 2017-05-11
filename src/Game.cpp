#include <Game.h>
#include <BWAPI/Game.h>

void Game_sendText(Game* self, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    Game_vSendText(self, format, args);
    va_end (args);
}

void Game_vSendText(Game* self, const char *format, va_list args) {
    reinterpret_cast<BWAPI::Game*>(self)->vSendText(format, args);
}
