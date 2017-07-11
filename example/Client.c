// mingw on linux: i686-w64-mingw32-gcc -mabi=ms -o Client.exe Client.c -I../include -L. -lBWAPIC
// gcc   on linux: you can't connect to BW using client, because openbw/bwapi v4.1.12 does not support it :(

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep sleep
#endif

#include <assert.h>
#include <stdio.h>

#include <Client.h>
#include <Game.h>
#include <BwString.h>
#include <Iterator.h>
#include <Player.h>

static Game* BWGame;
static Client* BWClient;

void reconnect() {
    if (!Client_isConnected(BWClient)) {
        fprintf(stderr, "Reconnecting...\n");
        while(!Client_connect(BWClient)) {
            Sleep(1);
        }
    }
    BWGame = BWAPIC_getGame();
}

int main() {
    BWClient = BWAPIC_getClient();

    reconnect();

    while ( !Game_isInGame(BWGame) ) {
        Client_update(BWClient);
        reconnect();
    }

    fprintf(stderr, "Starting match\n");
    Game_sendText(BWGame, "Hello world!");

    BwString* const map_name = Game_mapName(BWGame);
    assert(map_name);
    Game_sendText(BWGame, "The map is '%s'!", BwString_data(map_name));
    BwString_release(map_name);

    if (Game_isReplay(BWGame)) {
        Game_sendText(BWGame, "The following players are in this replay:");
        Iterator* const players = (Iterator*) Game_getPlayers(BWGame);
        assert(players);

        for (; Iterator_valid(players); Iterator_next(players)) {
            Player* const player = (Player*) Iterator_get(players);
            assert(player);

            if ( !Player_isNeutral(player) ) {
                BwString* const player_name = Player_getName(player);
                assert(player_name);
                Race player_race = Player_getRace(player);
                Game_sendText(BWGame, "'%s', playing as %d!", BwString_data(player_name), player_race.id);
                BwString_release(player_name);
            }
        }
        Iterator_release(players);
    }

    while(Game_isInGame(BWGame))
    {
        const Position text_position = { .x = 300, .y = 0 };
        Game_drawTextScreen(BWGame, text_position, "FPS: %f", Game_getAverageFPS(BWGame));

        Client_update(BWClient);
        reconnect();
    }
    fprintf(stderr, "Game ended\n");
    return 0;
}
