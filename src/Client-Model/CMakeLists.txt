cmake_minimum_required(VERSION 3.22)
project(Client_Model)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(SFML COMPONENTS system window graphics network audio)

add_executable(Client_Model
        client.h
        client_class.cpp
        client_main.cpp
        common_camera.cpp
        common_camera.h
        common_game_screen.cpp
        common_game_screen.h
        common_ground.cpp
        common_ground.h
        common_model.cpp
        common_model.h
        common_protocol.cpp
        common_protocol.h
        common_trike.cpp
        common_trike.h
        common_unit.cpp
        common_unit.h)

target_link_libraries(Client_Model sfml-graphics sfml-window sfml-system sfml-audio)