CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17

all: test_block_position test_path_node test_terrain_map test_terrain_mobility

test_block_position: block_position_test.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/block_position.cpp

test_terrain_mobility: terrain_mobility_test.cpp ../src/fremen_mobility.cpp
	g++ $(CFLAGS) -o terrain_mobility.test terrain_mobility_test.cpp ../src/fremen_mobility.cpp

test_path_node: path_node_test.cpp ../src/path_node.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o path_node.test path_node_test.cpp ../src/path_node.cpp ../src/block_position.cpp

test_terrain_map: terrain_map_test.cpp ../src/terrain_map.cpp ../src/block_position.cpp ../src/path_node.cpp ../src/fremen_mobility.cpp
	g++ $(CFLAGS) -o terrain_map.test terrain_map_test.cpp ../src/terrain_map.cpp ../src/block_position.cpp ../src/path_node.cpp ../src/fremen_mobility.cpp

clean:
	rm -f core *.o block_position.test terrain_mobility.test path_node.test terrain_map.test