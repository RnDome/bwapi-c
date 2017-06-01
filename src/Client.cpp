#include <Client.h>

#include <BWAPI/Game.h>

namespace BWAPI
{

class Client
{
public:
    bool isConnected() const;
    bool connect();
    void disconnect();
    void update();
};
extern Client BWAPIClient;

}

Client* BWAPIC_getClient() {
    return reinterpret_cast<Client*>( &BWAPI::BWAPIClient );
}

bool Client_isConnected(Client* self) {
    return reinterpret_cast<BWAPI::Client*>(self)->isConnected();
}

bool Client_connect(Client* self) {
    return reinterpret_cast<BWAPI::Client*>(self)->connect();
}

void Client_disconnect(Client* self) {
    reinterpret_cast<BWAPI::Client*>(self)->disconnect();
}

void Client_update(Client* self) {
    reinterpret_cast<BWAPI::Client*>(self)->update();
}
