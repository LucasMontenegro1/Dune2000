//
// Created by lucas on 26/06/22.
//
#ifndef SERVER_GAMESHANDLER_H
#define SERVER_GAMESHANDLER_H
#include "mock_server.h"
#include "blocking_queue.h"
#include "GameHandler.h"


class GamesHandler {
    //std::map<std::string, MockServer*> games;
    std::map<std::string, GameHandler> games;
    public:

    /*
    bool create_game(std::string gameName, int limitPlayers, std::string playerName, int team);

    bool join_game(std::string gameName, std::string playerName, int team);

    void list_games();
    */
};


#endif //SERVER_GAMESHANDLER_H
