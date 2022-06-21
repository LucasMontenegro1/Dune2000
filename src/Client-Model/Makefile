CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
MAP_FILES = ../Model/Map/terrain_map.cpp ../Model/Map/block_position.cpp ../Model/Map/path_node.cpp
UNIT_FILES = ../Model/Entities/unit.cpp ../Model/Entities/teamable.cpp ../Model/Weapons/weapon.cpp
INFANTRY_FILES = ../Model/Entities/light_infantry.cpp ../Model/Mobility/infantry_mobility.cpp
VEHICLE_FILES = ../Model/Entities/tank.cpp ../Model/Entities/trike.cpp ../Model/Mobility/vehicle_mobility.cpp
WEAPON_FILES = ../Model/Weapons/assault_rifle.cpp ../Model/Weapons/cannon.cpp
BUILDING_FILES = ../Model/Entities/building.cpp ../Model/Entities/teamable.cpp ../Model/Map/block_position.cpp ../Server/configuration_loader.cpp
SRV_FILES = ../Server/mock_server.cpp ../Server/control_unit.cpp ../Server/entity_factory.cpp ../Server/configuration_loader.cpp
CLIENT_FILES = client_class.cpp common_camera.cpp common_game_screen.cpp common_ground.cpp common_model.cpp common_explosion.cpp  common_protocol.cpp common_pointer.cpp common_selector.cpp common_frames.cpp Button.cpp Button.h ConstructionMenu.cpp ConstructionMenu.h BuildingImageHandler.cpp BuildingImageHandler.h UnitImageHandler.cpp UnitImageHandler.h VehicleImageHandler.cpp VehicleImageHandler.h  UnitButton.h UnitButton.cpp
UNITS_FILES = common_tank.cpp common_trike.cpp common_unit.cpp 
WEAPONS_FILES = common_assault.cpp common_canyon.cpp
BUILDS_FILES = common_build.cpp common_windtrap.cpp



client: client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(INFANTRY_FILES) $(VEHICLE_FILES) $(WEAPON_FILES) $(UNIT_FILES) $(MAP_FILES) $(UNITS_FILES) $(WEAPONS_FILES) $(BUILDS_FILES)
	g++ $(CFLAGS) -o client client_main.cpp $(CLIENT_FILES) $(SRV_FILES) $(INFANTRY_FILES) $(VEHICLE_FILES) $(WEAPON_FILES) $(UNIT_FILES) $(MAP_FILES) $(UNITS_FILES) $(LIBS) $(WEAPONS_FILES) $(BUILDS_FILES)

