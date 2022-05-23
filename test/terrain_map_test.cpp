//
// Created by ignat on 21/05/22.
//

#include "./acutest.h"
#include "../src/terrain_map.h"
#include "../src/fremen_mobility.h"

void test_at(void)
{
	TerrainMap map(20, 22);

	TEST_CHECK(map.at(BlockPosition(0, 0)) == sand);
	TEST_CHECK(map.at(BlockPosition(19, 21)) == sand);
	TEST_EXCEPTION(map.at(BlockPosition(20, 0)), std::out_of_range);
	TEST_EXCEPTION(map.at(BlockPosition(0, 22)), std::out_of_range);
	TEST_EXCEPTION(map.at(BlockPosition(30, 30)), std::out_of_range);
}

void test_invalid_org_dst(void)
{
	TerrainMap map(4, 5);

	BlockPosition invalid_pos(5, 6);
	BlockPosition pos(0, 0);
	FremenMobility mob;

	TEST_EXCEPTION(map.get_path(invalid_pos, pos, &mob), std::out_of_range);
	TEST_EXCEPTION(map.get_path(pos, invalid_pos, &mob), std::out_of_range);
}

void test_path_to_self(void)
{
	TerrainMap map(4, 5);
	BlockPosition pos(3, 4);
	FremenMobility mob;

	std::list<BlockPosition> path = map.get_path(pos, pos, &mob);

	TEST_CHECK(path.size() == 1);
	TEST_CHECK(pos == path.front());
	TEST_CHECK(pos == path.back());
}

void test_straight_path_on_x(void)
{
	TerrainMap map(4, 5);
	BlockPosition org(3, 0);
	BlockPosition dst(3, 2);
	FremenMobility mob;

	std::list<BlockPosition> path = map.get_path(org, dst, &mob);
	auto it = path.cbegin();

	TEST_CHECK(path.size() == 3);
	TEST_CHECK(*it == org);
	++it;
	TEST_CHECK(*it == BlockPosition(3, 1));
	++it;
	TEST_CHECK(*it == dst);
}

void test_diagonal_path(void)
{
	TerrainMap map(4, 5);
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	FremenMobility mob;

	std::list<BlockPosition> path = map.get_path(org, dst, &mob);
	auto it = path.cbegin();

	TEST_CHECK(path.size() == 3);
	TEST_CHECK(*it == org);
	++it;
	TEST_CHECK(*it == BlockPosition(2, 1));
	++it;
	TEST_CHECK(*it == dst);
}

void test_change_terrain(void)
{
	TerrainMap map(4, 6);

	map.change_terrain(BlockPosition(0, 0), cliffs);
	map.change_terrain(BlockPosition(1, 1), dunes);
	map.change_terrain(BlockPosition(2, 2), sand);

	TEST_CHECK(map.at(0, 0) == cliffs);
	TEST_CHECK(map.at(1, 1) == dunes);
	TEST_CHECK(map.at(2, 2) == sand);
	TEST_EXCEPTION(map.change_terrain(BlockPosition(10, 10), cliffs), std::out_of_range);
}

TEST_LIST = {
	{"at_method", test_at},
	{"invalid_positions", test_invalid_org_dst},
	{"path_to_self", test_path_to_self},
	{"straight_path_on_x", test_straight_path_on_x},
	{"diagonal_path", test_diagonal_path},
	{"change_terrain", test_change_terrain},
	{NULL, NULL}
};