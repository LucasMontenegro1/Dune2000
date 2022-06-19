CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
MAP_FILES = ../Model/terrain_map.cpp ../Model/block_position.cpp ../Model/path_node.cpp
UNIT_FILES = ../Model/unit.cpp ../Model/teamable.cpp ../Model/Weapons/weapon.cpp
INFANTRY_FILES = ../Model/light_infantry.cpp ../Model/Mobility/infantry_mobility.cpp
VEHICLE_FILES = ../Model/tank.cpp ../Model/Mobility/vehicle_mobility.cpp
WEAPON_FILES = ../Model/Weapons/assault_rifle.cpp ../Model/Weapons/cannon.cpp
SRV_FILES = ../Server/mock_server.cpp ../Server/control_unit.cpp ../Server/entity_factory.cpp ../Server/configuration_loader.cpp
CLIENT_FILES = client_class.cpp common_camera.cpp common_game_screen.cpp common_ground.cpp common_model.cpp common_protocol.cpp common_pointer.cpp common_selector.cpp common_frames.cpp  
UNITS_FILES = common_tank.cpp common_trike.cpp common_unit.cpp 
WEAPONS_FILES = common_assault.cpp common_canyon.cpp


client: client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(INFANTRY_FILES) $(VEHICLE_FILES) $(WEAPON_FILES) $(UNIT_FILES) $(MAP_FILES) $(UNITS_FILES) $(WEAPONS_FILES)
	g++ $(CFLAGS) -o client client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(INFANTRY_FILES) $(VEHICLE_FILES) $(WEAPON_FILES) $(UNIT_FILES) $(MAP_FILES) $(UNITS_FILES) $(LIBS) $(WEAPONS_FILES)

