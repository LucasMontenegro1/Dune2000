//
// Created by ignat on 10/06/22.
//

#include "acutest.h"
#include "../src/Model/light_infantry.h"
#include <algorithm>

void test_teamable_construction(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);
	TEST_CHECK(!unit.is_dead());
	TEST_CHECK(unit.get_id() == 1);
	TEST_CHECK(unit.get_player_id() == 2);
	TEST_CHECK(unit.get_hp() == 50);
}

void test_reduce_hp(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);
	TEST_CHECK(unit.get_hp() == 50);
	unit.reduce_hp(30);
	TEST_CHECK(unit.get_hp() == 20);
	TEST_CHECK(!unit.is_dead());
	unit.reduce_hp(20);
	TEST_CHECK(unit.is_dead());
}

void test_movable_construction(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);
	TEST_CHECK(unit.get_pos() == BlockPosition(3, 0));
	TEST_CHECK(unit.get_state() == neutral);
	TEST_CHECK(unit.facing_pos() == BlockPosition(3, 0));
	TEST_CHECK(!unit.changed_position());
}

void test_movable_distance(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);
	double distance = unit.distance_to(BlockPosition(2, 0));
	TEST_CHECK(distance == 1);
}

void test_positions_at_range(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);
	std::vector<BlockPosition> v = unit.positions_at_range(2);
	TEST_CHECK(v.size() == 6);
	auto it = std::find(v.begin(), v.end(), BlockPosition(3, 0));
	TEST_CHECK(it != v.end()),
	it = std::find(v.begin(), v.end(), BlockPosition(1, 2));
	TEST_CHECK(it == v.end());
	/*
	 * posiciones en rango:
	 *      | | | | | |
	 *      |x| | | | |
	 *      |x|x| | | |
	 *      |x|x|x| | |
	 *
	 *      se toma la distancia por pitagoras
	 */
}

void test_light_infantry_creation(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	LightInfantry unit(1, 2, BlockPosition(3, 0), map, units);

	TEST_CHECK(unit.can_traverse(sand));
	TEST_CHECK(not unit.can_traverse(cliffs));
	TEST_CHECK(unit.get_class_id() == 1);
	TEST_CHECK(unit.get_type_id() == 1);
}

void test_move_diagonal(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> units;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	LightInfantry unit(1, 2, org, map, units);
	unit.move_to(dst);
	TEST_CHECK(unit.get_state() == moving);
	TEST_CHECK(unit.get_pos() == org);

	unit.act();
	TEST_CHECK(unit.changed_position());
	TEST_CHECK(unit.get_pos() == BlockPosition(2, 1));

	unit.act();
	TEST_CHECK(unit.changed_position());
	TEST_CHECK(unit.get_pos() == dst);
	TEST_CHECK(unit.get_state() == neutral); // llego a destino

	unit.act();
	TEST_CHECK(not unit.changed_position());
	TEST_CHECK(unit.get_pos() == dst);
}

void test_move_avoiding_obstacles(void)
{
	TerrainMap map(4, 5);
	map.change_terrain(BlockPosition(0, 1), cliffs);
	map.change_terrain(BlockPosition(0, 3), cliffs);
	map.change_terrain(BlockPosition(1, 3), cliffs);
	map.change_terrain(BlockPosition(2, 2), cliffs);
	map.change_terrain(BlockPosition(2, 1), cliffs);
	map.change_terrain(BlockPosition(1, 1), cliffs);
	std::map<unsigned int, TeamablePtr> units;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	LightInfantry unit(1, 2, org, map, units);
	unit.move_to(dst);
	TEST_CHECK(unit.get_state() == moving);
	TEST_CHECK(unit.get_pos() == org);

	unit.act();
	TEST_CHECK(unit.get_pos() == BlockPosition(3, 1));
	unit.act();
	TEST_CHECK(unit.get_pos() == BlockPosition(3, 2));
	unit.act();
	TEST_CHECK(unit.get_pos() == BlockPosition(2, 3));
	unit.act();
	TEST_CHECK(unit.get_pos() == dst);
}

TEST_LIST = {
	{"teamable", test_teamable_construction},
	{"reduce_hp", test_reduce_hp},
	{"movable", test_movable_construction},
	{"distance", test_movable_distance},
	{"positions_at_range", test_positions_at_range},
	{"light_infantry", test_light_infantry_creation},
	{"move_diagonal", test_move_diagonal},
	{"move_with_obstacles", test_move_avoiding_obstacles},
	{NULL, NULL}
};