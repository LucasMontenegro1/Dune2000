//
// Created by lucas on 21/05/22.
//

#include "Client.h"

Client::Client(const char* host , const char* port): skt(host, port){}

void Client::run() {
    loginScreen();
}

void Client::loginScreen() {

}