CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17
MAP_FILES = ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp
MOV_FILES = ../src/Model/movable.cpp ../src/Model/infantry_mobility.cpp

all: test_block_position test_path_node test_terrain_map test_terrain_mobility test_movable test_control_unit

test_block_position: block_position_test.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/Model/block_position.cpp

test_terrain_mobility: terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_mobility.test terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp

test_path_node: path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o path_node.test path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp

test_terrain_map: terrain_map_test.cpp $(MAP_FILES) ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_map.test terrain_map_test.cpp $(MAP_FILES) ../src/Model/infantry_mobility.cpp

test_movable: movable_test.cpp $(MOV_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o movable.test movable_test.cpp $(MOV_FILES) $(MAP_FILES)

test_control_unit: control_unit_test.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)
	g++ $(CFLAGS) -o control_unit.test control_unit_test.cpp ../src/Server/control_unit.cpp $(MOV_FILES) $(MAP_FILES)

clean:
	rm -f core *.o *.test