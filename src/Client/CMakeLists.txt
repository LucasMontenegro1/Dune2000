cmake_minimum_required(VERSION 3.22)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_executable(Client main.cpp Client.cpp firstwindow.cpp ui_firstwindow.h sockets.cpp SocketException.cpp)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(Qt5Multimedia REQUIRED )
find_package(Qt5MultimediaWidgets REQUIRED)

target_link_libraries(Client
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        )
