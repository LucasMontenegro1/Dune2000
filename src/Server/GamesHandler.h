//
// Created by lucas on 26/06/22.
//
#ifndef SERVER_GAMESHANDLER_H
#define SERVER_GAMESHANDLER_H
#include "mock_server.h"
#include "blocking_queue.h"
#include "Game.h"

class GamesHandler {
    std::mutex mute;
    std::map<std::string, Game> games;
    bool findGame(const std::string&);

    //std::map<std::string, MockServer*> games;
    //MockServer game;
    //BlockingQueue receiver;
    
    public:
/*
    void push_order(const T &val);

    void update();

    T send_state();
*/
    /*
    bool create_game(std::string gameName, int limitPlayers, std::string playerName, int team);

    bool join_game(std::string gameName, std::string playerName, int team);

    void list_games();
    */
    void runGameIfCOmpleted(std::string& name);
};


#endif //SERVER_GAMESHANDLER_H
