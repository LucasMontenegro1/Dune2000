//
// Created by lucas on 03/07/22.
//

#include "Game.h"
#include <unistd.h>

Game::Game(const string& name , const int players):is_running(false) {
    currentPlayers = 1;
    this->name = name;
    max_players = players;
}

const std::string Game::getName() {
    return this->name;
}

const int Game::getCurrentPlayers() {
    return this->currentPlayers;
}

const int Game::getMaxPlayers() {
    return this->max_players;
}

bool Game::addPlayer() {
    if (verifySize()) {
        currentPlayers++;
        return true;
    }
    return false;
}

bool Game::isCompleted() {
    if (this->currentPlayers == this->max_players){
        is_running = true;
        return true;
    }
    return false;
}

void Game::OrderReciever(){
    //pr.recieveOrder()
    //update(Order);
}

void Game::run() {
    std::thread orders(&Game::OrderReciever, this);
    while(is_running){
        //update()
        sleep(1);
    }
    orders.join();
}

void Game::stop() {
    is_running = false;
}

bool Game::verifySize() {
    if (currentPlayers+1 <= max_players) {
        return true;
    }
    return false;
}
