//
// Created by lucas on 26/06/22.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <atomic>
#include "../Common/Sockets.h"
#include "GamesHandler.h"
#include "Protocol.h"
#include "ClientHandler.h"
#include <vector>


class Server {
    std::vector<ClientHandler*> clients;
    Protocol pr;
    Socket skt;
    std::atomic<bool> is_running;
    GamesHandler gamesHandler;
public:
    explicit Server(const char* servicename);
    ~Server();
    void run();

    void listener();
};


#endif //SERVER_SERVER_H
