//
// Created by lucas on 03/07/22.
//

#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#include <string>
#include "Thread.h"
#include "mock_server.h"

class Game : Thread{
private:
    MockServer* server;
    std::string name;
    bool is_running;
    int max_players;
    int currentPlayers;
    bool verifySize();
    void OrderReciever();
public:
    Game(const std::string&, const int);
    const std::string getName();
    const int getCurrentPlayers();
    const int getMaxPlayers();
    bool addPlayer();
    bool isCompleted();
    void run() override;
    void stop() override;
};


#endif //SERVER_GAME_H
