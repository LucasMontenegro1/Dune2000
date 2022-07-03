//
// Created by lucas on 03/07/22.
//

#include "Game.h"

Game::Game(const string &, const int) {

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
    return false;
}

bool Game::isCompleted() {
    return false;
}

void Game::run() {

}

void Game::stop() {

}
