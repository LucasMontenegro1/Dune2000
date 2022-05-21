//
// Created by lucas on 21/05/22.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include "sockets.h"

class Client {
 public:
    void run();
    void loginScreen();
    Client(const char*, const char*);
 private:
    Socket skt;
};


#endif //CLIENT_CLIENT_H
