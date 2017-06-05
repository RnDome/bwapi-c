#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

// return pointer to the client via &BWAPI::BWAPIClient;
Client* BWAPIC_getClient();

bool Client_isConnected(Client* self);
bool Client_connect(Client* self);
void Client_disconnect(Client* self);
void Client_update(Client* self);

#ifdef __cplusplus
} // extern "C"
#endif
