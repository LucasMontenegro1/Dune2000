//
// Created by lucas on 26/06/22.
//

#include <sys/socket.h>
#include "ClientHandler.h"
#include "../Common/SocketException.h"

#define JOIN_GAME 1
#define LIST_GAMES 2
#define CREATE_GAME 3

ClientHandler::ClientHandler(Socket skt, GamesHandler *gamesHandler)
        : is_over(false), games(gamesHandler) {
}

void ClientHandler::run() {
    while (!is_over) {
        try {
            bool was_closed = false;
            int instr = pr.decodeLoginInstruction(peer, was_closed);
            this->is_over = was_closed;
            if (!is_over) {
                switch (instr) {
                    case JOIN_GAME:
                        break;
                    case LIST_GAMES:
                        break;
                    case CREATE_GAME:
                        break;
                }
            }

        } catch (SocketException &e) {
            is_over = true;
            std::cout<< e.what();
        }
    }
}

void ClientHandler::stop() {
    peer.shutdown(SHUT_RDWR);
    is_over = true;
}

bool ClientHandler::isOver() {
    return is_over;
}
