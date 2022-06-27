//
// Created by lucas on 26/06/22.
//

#include <cstdint>
#include "Protocol.h"
#define OPERATION 1

Protocol::Protocol() = default;

int Protocol::decodeLoginInstruction(Socket &socket, bool& was_closed) {
    uint8_t command;
    if (!socket.recieve(&command, OPERATION)) {
        was_closed = true;
        return -1;
    }

    return (int) command;
}
