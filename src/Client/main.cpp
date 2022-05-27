#include <iostream>
#include <QApplication>
#include <QErrorMessage>
#include <QDir>
#include "Client.h"
#include "firstwindow.h"
#include "SocketException.h"

int main(int argc, char* argv[]) {

    try {
        auto *a = new QApplication(argc, argv);
        std::string host;
        std::string port;
        FIrstWindow w(host, port);
        w.show();
        a->exec();
        if (!host.empty() && !port.empty()) {
            Client client(host.c_str(), port.c_str());
            delete a;
            client.run();
        }
    }catch (SocketException &e){
        QErrorMessage msg;
        msg.showMessage("CONNECTION ERROR");
        msg.exec();
        return 1;
    }
    return 0;
}
