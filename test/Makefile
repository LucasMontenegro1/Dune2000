CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17

all: test_block_position test_path_node test_terrain_map test_terrain_mobility

test_block_position: block_position_test.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/Model/block_position.cpp

test_terrain_mobility: terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_mobility.test terrain_mobility_test.cpp ../src/Model/infantry_mobility.cpp

test_path_node: path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp
	g++ $(CFLAGS) -o path_node.test path_node_test.cpp ../src/Model/path_node.cpp ../src/Model/block_position.cpp

test_terrain_map: terrain_map_test.cpp ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o terrain_map.test terrain_map_test.cpp ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp ../src/Model/infantry_mobility.cpp

test_control_unit: control_unit_test.cpp ../src/Server/control_unit.cpp ../src/Server/model_unit.cpp ../src/Server/task_create.cpp ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp ../src/Model/infantry_mobility.cpp
	g++ $(CFLAGS) -o control_unit.test control_unit_test.cpp ../src/Server/control_unit.cpp ../src/Server/model_unit.cpp ../src/Server/task_create.cpp ../src/Model/terrain_map.cpp ../src/Model/block_position.cpp ../src/Model/path_node.cpp ../src/Model/infantry_mobility.cpp

clean:
	rm -f core *.o *.test