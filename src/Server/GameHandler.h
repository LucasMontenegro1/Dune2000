
#ifndef SERVER_GAMEHANDLER_H
#define SERVER_GAMEHANDLER_H
#include "mock_server.h"
#include "blocking_queue.h"



class GameHandler {
    BlockingQueue receiver;
    MockServer game;
    std::map<std::string, BlockingQueue*> senders;

    public:

};
#endif