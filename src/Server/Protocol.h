//
// Created by lucas on 26/06/22.
//

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "../Common/Sockets.h"

class Protocol {

public:
    Protocol();
    int decodeLoginInstruction(Socket& socket, bool& was_closed);
    void sendMapList();
};


#endif
