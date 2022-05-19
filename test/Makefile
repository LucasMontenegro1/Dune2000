CFLAGS = -Wall -Werror -pedantic -pedantic-errors -std=c++17

test_block_position: block_position_test.cpp ../src/block_position.cpp
	g++ $(CFLAGS) -o test_block_position block_position_test.cpp ../src/block_position.cpp

clean:
	rm -f core *.o test_block_position