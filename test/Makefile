CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17
MAP_FILES = ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp
UNIT_FILES = ../src/Model/unit.cpp ../src/Model/teamable.cpp ../src/Model/weapon.cpp

all: test_block_position test_path_node test_terrain_map test_terrain_mobility test_tank test_light_infantry test_weapons

test_block_position: block_position_test.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/Model/block_position.cpp

test_terrain_mobility: terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_mobility.test terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp

test_path_node: path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o path_node.test path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp

test_terrain_map: terrain_map_test.cpp $(MAP_FILES) ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_map.test terrain_map_test.cpp $(MAP_FILES) ../src/Model/infantry_mobility.cpp

test_light_infantry: light_infantry_test.cpp ../src/Model/light_infantry.cpp ../src/Model/assault_rifle.cpp ../src/Model/infantry_mobility.cpp $(UNIT_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o light_inf.test light_infantry_test.cpp ../src/Model/light_infantry.cpp ../src/Model/assault_rifle.cpp ../src/Model/infantry_mobility.cpp $(UNIT_FILES) $(MAP_FILES)

test_weapons: weapon_test.cpp ../src/Model/weapon.cpp ../src/Model/assault_rifle.cpp
	g++ $(CFLAGS) -o weapon.test weapon_test.cpp ../src/Model/weapon.cpp ../src/Model/assault_rifle.cpp

test_tank: tank_test.cpp ../src/Model/tank.cpp ../src/Model/cannon.cpp ../src/Model/vehicle_mobility.cpp $(UNIT_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o tank.test tank_test.cpp ../src/Model/tank.cpp ../src/Model/cannon.cpp ../src/Model/vehicle_mobility.cpp $(UNIT_FILES) $(MAP_FILES)

test_control_unit: control_unit_test.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o control_unit.test control_unit_test.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)

test_mock_srv: mock_server_test.cpp ../src/Server/mock_server.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o mock_srv.test mock_server_test.cpp ../src/Server/mock_server.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)

clean:
	rm -f core *.o *.test