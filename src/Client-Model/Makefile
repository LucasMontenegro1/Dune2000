CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17 
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
MAP_FILES = ../Model/terrain_map.cpp ../Model/block_position.cpp ../Model/path_node.cpp
MOV_FILES = ../Model/movable.cpp ../Model/infantry_mobility.cpp
SRV_FILES = ../Server/mock_server.cpp ../Server/control_unit.cpp
CLIENT_FILES = client_class.cpp common_camera.cpp common_game_screen.cpp common_ground.cpp common_model.cpp common_protocol.cpp common_trike.cpp common_unit.cpp common_pointer.cpp common_selector.cpp

client: client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(MOV_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o client client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(MOV_FILES) $(MAP_FILES) $(LIBS)
