CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17

test_block_position: block_position_test.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/block_position.cpp

test_terrain_movility: terrain_movility_test.cpp ../src/fremen_movility.cpp
	g++ $(CFLAGS) -o terrain_movility.test terrain_movility_test.cpp ../src/fremen_movility.cpp

test_path_node: path_node_test.cpp ../src/path_node.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o path_node.test path_node_test.cpp ../src/path_node.cpp ../src/block_position.cpp

clean:
	rm -f core *.o block_position.test terrain_movility.test path_node.test