//
// Created by ignat on 03/06/22.
//

#include "acutest.h"
#include "../src/Model/movable.h"

void test_neutral_act(void)
{
	TerrainMap map(4, 5);
	Movable unit(0, BlockPosition(0, 0), map);
	unit.act();

	TEST_CHECK(not unit.has_changed());
	TEST_CHECK(unit.is_at_position(BlockPosition(0, 0)));
}

void test_move_diagonal(void)
{
	TerrainMap map(4, 5);
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	Movable unit(0, org, map);
	unit.move_to(dst);

	TEST_CHECK(unit.is_at_position(org));
	unit.act();
	TEST_CHECK(unit.has_changed());
	TEST_CHECK(unit.is_at_position(BlockPosition(2, 1)));
	unit.act();
	TEST_CHECK(unit.has_changed());
	TEST_CHECK(unit.is_at_position(dst));
	unit.act();
	TEST_CHECK(not unit.has_changed());
	TEST_CHECK(unit.is_at_position(dst));
}

void test_move_avoiding_obstacles(void)
{
	TerrainMap map(4, 5);
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	map.change_terrain(BlockPosition(0, 1), cliffs);
	//map.change_terrain(BlockPosition(0, 2), cliffs);
	map.change_terrain(BlockPosition(0, 3), cliffs);
	map.change_terrain(BlockPosition(1, 3), cliffs);
	map.change_terrain(BlockPosition(2, 2), cliffs);
	map.change_terrain(BlockPosition(2, 1), cliffs);
	map.change_terrain(BlockPosition(1, 1), cliffs);
	Movable unit(0, org, map);
	unit.move_to(dst);

	TEST_CHECK(unit.is_at_position(org));
	unit.act();
	TEST_CHECK(unit.is_at_position(BlockPosition(3, 1)));
	unit.act();
	TEST_CHECK(unit.is_at_position(BlockPosition(3, 2)));
	unit.act();
	TEST_CHECK(unit.is_at_position(BlockPosition(2, 3)));
	unit.act();
	TEST_CHECK(unit.is_at_position(dst));
}

TEST_LIST = {
	{"neutral_act", test_neutral_act},
	{"move_diagonal", test_move_diagonal},
	{"move_avoiding_obstacles", test_move_avoiding_obstacles},
	{NULL, NULL}
};