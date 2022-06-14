//
// Created by ignat on 10/06/22.
//

#include "acutest.h"
#include "../src/Model/light_infantry.h"

typedef std::shared_ptr<Unit> UnitPtr;

void test_create(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	LightInfantry inf(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	TEST_CHECK(inf.get_id() == 1);
	TEST_CHECK(inf.get_player_id() == 2);
	TEST_CHECK(inf.get_class_id() == 1); // infanteria
	TEST_CHECK(inf.get_type_id() == 1); // infanteria ligera
	TEST_CHECK(inf.get_state() == creating);
	TEST_CHECK(not inf.is_movable());
	TEST_CHECK(not inf.can_attack());
	inf.update(60000); // 1 minutos
	TEST_CHECK(inf.get_state() == neutral);
	TEST_CHECK(inf.is_movable());
	TEST_CHECK(inf.can_attack());
	TEST_CHECK(inf.get_hp() == 50);
	TEST_CHECK(inf.get_weapon_id() == 1); // rifle de asalto
	TEST_CHECK(inf.get_position() == BlockPosition(3, 0));
	TEST_CHECK(inf.facing_position() == BlockPosition(3, 0));
}

void test_create_faster(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	LightInfantry inf(1, 2, BlockPosition(3, 0), map, game_objects, 2);
	TEST_CHECK(inf.get_state() == creating);
	inf.update(30000); // 30 secs
	TEST_CHECK(inf.get_state() == neutral);
}

void test_create_slower(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	LightInfantry inf(1, 2, BlockPosition(3, 0), map, game_objects, 0.5);
	TEST_CHECK(inf.get_state() == creating);
	inf.update(60000);
	TEST_CHECK(inf.get_state() == creating);
	inf.update(60000);
	TEST_CHECK(inf.get_state() == neutral);
}

void test_reduce_hp(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	LightInfantry inf(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	inf.update(60000);
	TEST_CHECK(not inf.is_dead());
	inf.reduce_hp(20);
	TEST_CHECK(inf.get_hp() == 30);
	inf.reduce_hp(30);
	TEST_CHECK(inf.is_dead());
}

void test_move_diagonal(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	LightInfantry inf(1, 2, org, map, game_objects, 1);
	inf.update(60000);
	inf.move_to(dst);
	TEST_CHECK(inf.get_state() == moving);
	TEST_CHECK(inf.get_position() == org);

	inf.update(0);
	TEST_CHECK(not inf.changed_position());
	TEST_CHECK(inf.get_position() == org);

	inf.update(450); // hace un bloque cada 450ms
	TEST_CHECK(inf.changed_position());
	TEST_CHECK(inf.get_position() == BlockPosition(2, 1));

	inf.update(440);
	TEST_CHECK(not inf.changed_position());
	TEST_CHECK(inf.get_position() == BlockPosition(2, 1));

	inf.update(10);
	TEST_CHECK(inf.changed_position());
	TEST_CHECK(inf.get_position() == dst);
	TEST_CHECK(inf.get_state() == neutral);

	inf.update(450);
	TEST_CHECK(not inf.changed_position());
	TEST_CHECK(inf.get_position() == dst);
	TEST_CHECK(inf.get_state() == neutral);
}

void test_move_through_dunes_slower(void)
{
	TerrainMap map(4, 5);
	map.change_terrain(BlockPosition(2, 1), dunes);
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	LightInfantry inf(1, 2, org, map, game_objects, 1);
	inf.update(60000);
	inf.move_to(dst);

	inf.update(450);
	TEST_CHECK(inf.changed_position());
	TEST_CHECK(inf.get_position() == BlockPosition(2, 1));

	inf.update(450); // mitad de velocidad en las dunas
	TEST_CHECK(not inf.changed_position());
	TEST_CHECK(inf.get_position() == BlockPosition(2, 1));

	inf.update(450);
	TEST_CHECK(inf.changed_position());
	TEST_CHECK(inf.get_position() == dst);
	TEST_CHECK(inf.get_state() == neutral);
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
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	LightInfantry inf(1, 2, org, map, game_objects, 1);
	inf.update(60000);
	inf.move_to(dst);

	inf.update(450);
	TEST_CHECK(inf.get_position() == BlockPosition(3, 1));
	inf.update(450);
	TEST_CHECK(inf.get_position() == BlockPosition(3, 2));
	inf.update(450);
	TEST_CHECK(inf.get_position() == BlockPosition(2, 3));
	inf.update(450);
	TEST_CHECK(inf.get_position() == dst);
}

void test_neutral_no_enemies(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 2, BlockPosition(3, 1), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	TEST_CHECK(inf1->get_state() == neutral);
	TEST_CHECK(inf2->get_state() == neutral);
	inf1->update(0); // no ncesita pasar tiempo para setear un objetivo
	inf2->update(0);
	TEST_CHECK(inf1->get_state() == neutral);
	TEST_CHECK(inf2->get_state() == neutral);
	inf1->update(167);
	inf2->update(167);
	TEST_CHECK(inf1->get_hp() == 50);
	TEST_CHECK(inf2->get_hp() == 50);
}

void test_neutral_with_enemies(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 1, BlockPosition(3, 1), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	TEST_CHECK(inf1->get_state() == neutral);
	TEST_CHECK(inf2->get_state() == neutral);
	inf1->update(0); // no ncesita pasar tiempo para setear un objetivo
	inf2->update(0);
	TEST_CHECK(inf1->get_state() == autoattacking);
	TEST_CHECK(inf2->get_state() == autoattacking);
	inf1->update(167); // tanque dispara 1 x segundo
	inf2->update(167);
	TEST_CHECK(inf1->get_hp() == 47);
	TEST_CHECK(inf2->get_hp() == 47);
}

void test_neutral_loses_target(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 1, BlockPosition(2, 2), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	TEST_CHECK(inf1->get_state() == neutral);
	TEST_CHECK(inf2->get_state() == neutral);
	inf1->update(0);
	inf2->update(0);
	TEST_CHECK(inf1->get_state() == autoattacking);
	TEST_CHECK(inf2->get_state() == autoattacking);
	inf2->move_to(BlockPosition(2, 3));
	TEST_CHECK(inf1->get_state() == autoattacking);
	TEST_CHECK(inf2->get_state() == moving);
	inf1->update(100);
	TEST_CHECK(inf1->get_state() == autoattacking);
	TEST_CHECK(inf2->get_hp() == 50); // todavia no ataco a tank2
	inf2->update(450); // tanque 2 se mueve fuera del rango
	TEST_CHECK(inf2->get_position() == BlockPosition(2, 3));
	inf1->update(100);
	inf2->update(100);
	TEST_CHECK(inf1->get_hp() == 50);
	TEST_CHECK(inf2->get_hp() == 50);
	TEST_CHECK(inf1->get_state() == neutral);
	TEST_CHECK(inf2->get_state() == neutral);
}

void test_attack_still_target(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 1, BlockPosition(0, 3), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	inf1->attack(2); // notar que tank2 esta fuera de rango. tank1 tiene que acercarse
	TEST_CHECK(inf1->get_state() == chasing);
	inf1->update(400);
	TEST_CHECK(inf1->get_position() == BlockPosition(3, 0));
	TEST_CHECK(inf1->get_state() == chasing);
	inf1->update(100);
	TEST_CHECK(inf1->changed_position());
	TEST_CHECK(inf1->get_state() == attacking);
	inf1->update(167);
	TEST_CHECK(inf2->get_hp() == 47);
}

void test_attack_and_chase(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 1, BlockPosition(1, 2), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	inf1->attack(2);
	inf2->move_to(BlockPosition(0, 3));
	TEST_CHECK(inf1->get_state() == attacking);
	TEST_CHECK(inf2->get_state() == moving);
	inf1->update(100); // usa estos 100ms para recargar el arma
	inf2->update(450); // se mueve
	TEST_CHECK(inf2->changed_position());
	TEST_CHECK(inf2->get_position() == BlockPosition(0, 3));
	inf1->update(100);
	inf2->update(100);
	TEST_CHECK(inf1->get_state() == chasing);
	inf1->update(450);
	TEST_CHECK(inf1->changed_position());
	TEST_CHECK(inf1->get_state() == attacking);
	inf1->update(67);
	TEST_CHECK(inf2->get_hp() == 47);
}

void test_target_dies(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr inf1 = std::make_shared<LightInfantry>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr inf2 = std::make_shared<LightInfantry>(2, 1, BlockPosition(1, 2), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf1->get_id(), inf1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(inf2->get_id(), inf2));
	inf1->update(60000);
	inf2->update(60000);
	inf1->attack(2);
	for (unsigned int i = 1; i <= 16; i++) {
		inf1->update(167);
		TEST_CHECK(inf2->get_hp() == 50 - 3 * i);
	}
	inf1->update(167);
	TEST_CHECK(inf2->is_dead());
	TEST_CHECK(inf1->get_state() == attacking);
	inf1->update(0);
	TEST_CHECK(inf1->get_state() == neutral);
}

TEST_LIST = {
	{"create", test_create},
	{"create_faster", test_create_faster},
	{"create_slower", test_create_slower},
	{"reduce_hp", test_reduce_hp},
	{"move_diagonal", test_move_diagonal},
	{"move_dunes", test_move_through_dunes_slower},
	{"move_with_obstacles", test_move_avoiding_obstacles},
	{"neutral_no_enemies", test_neutral_no_enemies},
	{"neutral_with_enemies", test_neutral_with_enemies},
	{"neutral_lose_target", test_neutral_loses_target},
	{"attack_still_target", test_attack_still_target},
	{"attack_and_chase", test_attack_and_chase},
	{"kill_target", test_target_dies},
	{NULL, NULL}
};