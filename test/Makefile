CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17

test_block_position: block_position_test.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o block_position.test block_position_test.cpp ../src/block_position.cpp

test_terrain_movility: terrain_movility_test.cpp ../src/fremen_movility.cpp
	g++ $(CFLAGS) -o terrain_movility.test terrain_movility_test.cpp ../src/fremen_movility.cpp

clean:
	rm -f core *.o test_block_position