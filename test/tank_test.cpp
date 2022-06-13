//
// Created by ignat on 12/06/22.
//

#include "acutest.h"
#include "../src/Model/tank.h"

typedef std::shared_ptr<Unit> UnitPtr;

/*
TeamablePtr foo(const UnitPtr &ptr)
{
	return std::dynamic_pointer_cast<TeamablePtr>(ptr);
}
 */

void test_create(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	Tank tank(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	TEST_CHECK(tank.get_id() == 1);
	TEST_CHECK(tank.get_player_id() == 2);
	TEST_CHECK(tank.get_class_id() == 2); // vehiculos
	TEST_CHECK(tank.get_type_id() == 2); // tanque
	TEST_CHECK(tank.get_state() == creating);
	TEST_CHECK(not tank.is_movable());
	TEST_CHECK(not tank.can_attack());
	tank.update(240000); // 4 minutos
	TEST_CHECK(tank.get_state() == neutral);
	TEST_CHECK(tank.is_movable());
	TEST_CHECK(tank.can_attack());
	TEST_CHECK(tank.get_hp() == 30);
	TEST_CHECK(tank.get_weapon_id() == 2); // cañon
	TEST_CHECK(tank.get_position() == BlockPosition(3, 0));
	TEST_CHECK(tank.facing_position() == BlockPosition(3, 0));
}

void test_create_faster(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	Tank tank(1, 2, BlockPosition(3, 0), map, game_objects, 2);
	TEST_CHECK(tank.get_state() == creating);
	tank.update(120000); // 2 minutos y medio
	TEST_CHECK(tank.get_state() == neutral);
}

void test_create_slower(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	Tank tank(1, 2, BlockPosition(3, 0), map, game_objects, 0.5);
	TEST_CHECK(tank.get_state() == creating);
	tank.update(240000);
	TEST_CHECK(tank.get_state() == creating);
	tank.update(240000);
	TEST_CHECK(tank.get_state() == neutral);
}

void test_reduce_hp(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	Tank tank(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	tank.update(240000);
	TEST_CHECK(not tank.is_dead());
	tank.reduce_hp(20);
	TEST_CHECK(tank.get_hp() == 10);
	tank.reduce_hp(10);
	TEST_CHECK(tank.is_dead());
}

void test_move_diagonal(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	Tank tank(1, 2, org, map, game_objects, 1);
	tank.update(240000);
	tank.move_to(dst);
	TEST_CHECK(tank.get_state() == moving);
	TEST_CHECK(tank.get_position() == org);

	tank.update(0);
	TEST_CHECK(not tank.changed_position());
	TEST_CHECK(tank.get_position() == org);

	tank.update(200); // tanque hace un bloque cada 200ms
	TEST_CHECK(tank.changed_position());
	TEST_CHECK(tank.get_position() == BlockPosition(2, 1));

	tank.update(100);
	TEST_CHECK(not tank.changed_position());
	TEST_CHECK(tank.get_position() == BlockPosition(2, 1));

	tank.update(100);
	TEST_CHECK(tank.changed_position());
	TEST_CHECK(tank.get_position() == dst);
	TEST_CHECK(tank.get_state() == neutral);

	tank.update(200);
	TEST_CHECK(not tank.changed_position());
	TEST_CHECK(tank.get_position() == dst);
	TEST_CHECK(tank.get_state() == neutral);
}

void test_move_through_dunes_slower(void)
{
	TerrainMap map(4, 5);
	map.change_terrain(BlockPosition(2, 1), dunes);
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	Tank tank(1, 2, org, map, game_objects, 1);
	tank.update(240000);
	tank.move_to(dst);

	tank.update(200);
	TEST_CHECK(tank.changed_position());
	TEST_CHECK(tank.get_position() == BlockPosition(2, 1));

	tank.update(200); // mitad de velocidad en las dunas
	TEST_CHECK(not tank.changed_position());
	TEST_CHECK(tank.get_position() == BlockPosition(2, 1));

	tank.update(200);
	TEST_CHECK(tank.changed_position());
	TEST_CHECK(tank.get_position() == dst);
	TEST_CHECK(tank.get_state() == neutral);
}

void test_move_avoiding_obstacles(void)
{
	TerrainMap map(4, 5);
	map.change_terrain(BlockPosition(0, 1), cliffs);
	map.change_terrain(BlockPosition(0, 3), cliffs);
	map.change_terrain(BlockPosition(1, 3), cliffs);
	map.change_terrain(BlockPosition(2, 2), cliffs);
	map.change_terrain(BlockPosition(2, 1), peaks);
	map.change_terrain(BlockPosition(1, 1), cliffs);
	std::map<unsigned int, TeamablePtr> game_objects;
	BlockPosition org(3, 0);
	BlockPosition dst(1, 2);
	Tank tank(1, 2, org, map, game_objects, 1);
	tank.update(240000);
	tank.move_to(dst);

	tank.update(200);
	TEST_CHECK(tank.get_position() == BlockPosition(3, 1));
	tank.update(200);
	TEST_CHECK(tank.get_position() == BlockPosition(3, 2));
	tank.update(200);
	TEST_CHECK(tank.get_position() == BlockPosition(2, 3));
	tank.update(200);
	TEST_CHECK(tank.get_position() == dst);
}

void test_neutral_no_enemies(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr tank1 = std::make_shared<Tank>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr tank2 = std::make_shared<Tank>(2, 2, BlockPosition(3, 1), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank1->get_id(), tank1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank2->get_id(), tank2));
	tank1->update(240000);
	tank2->update(240000);
	TEST_CHECK(tank1->get_state() == neutral);
	TEST_CHECK(tank2->get_state() == neutral);
	tank1->update(0); // no ncesita pasar tiempo para setear un objetivo
	tank2->update(0);
	TEST_CHECK(tank1->get_state() == neutral);
	TEST_CHECK(tank2->get_state() == neutral);
	tank1->update(1000);
	tank2->update(1000);
	TEST_CHECK(tank1->get_hp() == 30);
	TEST_CHECK(tank2->get_hp() == 30);
}

void test_neutral_with_enemies(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr tank1 = std::make_shared<Tank>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr tank2 = std::make_shared<Tank>(2, 1, BlockPosition(3, 1), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank1->get_id(), tank1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank2->get_id(), tank2));
	tank1->update(240000);
	tank2->update(240000);
	TEST_CHECK(tank1->get_state() == neutral);
	TEST_CHECK(tank2->get_state() == neutral);
	tank1->update(0); // no ncesita pasar tiempo para setear un objetivo
	tank2->update(0);
	TEST_CHECK(tank1->get_state() == autoattacking);
	TEST_CHECK(tank2->get_state() == autoattacking);
	tank1->update(1000); // tanque dispara 1 x segundo
	tank2->update(1000);
	TEST_CHECK(tank1->get_hp() == 23); // daño del cañon es 7
	TEST_CHECK(tank2->get_hp() == 23);
}

void test_neutral_loses_target(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr tank1 = std::make_shared<Tank>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr tank2 = std::make_shared<Tank>(2, 1, BlockPosition(2, 3), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank1->get_id(), tank1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank2->get_id(), tank2));
	tank1->update(240000);
	tank2->update(240000);
	TEST_CHECK(tank1->get_state() == neutral);
	TEST_CHECK(tank2->get_state() == neutral);
	tank1->update(0);
	tank2->update(0);
	TEST_CHECK(tank1->get_state() == autoattacking);
	TEST_CHECK(tank2->get_state() == autoattacking);
	tank2->move_to(BlockPosition(2, 4));
	TEST_CHECK(tank1->get_state() == autoattacking);
	TEST_CHECK(tank2->get_state() == moving);
	tank1->update(200);
	TEST_CHECK(tank1->get_state() == autoattacking);
	TEST_CHECK(tank2->get_hp() == 30); // todavia no ataco a tank2
	tank2->update(200); // tanque 2 se mueve fuera del rango
	TEST_CHECK(tank2->get_position() == BlockPosition(2, 4));
	tank1->update(800);
	tank2->update(800);
	TEST_CHECK(tank1->get_hp() == 30);
	TEST_CHECK(tank2->get_hp() == 30);
	TEST_CHECK(tank1->get_state() == neutral);
	TEST_CHECK(tank2->get_state() == neutral);
}

void test_attack_still_target(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr tank1 = std::make_shared<Tank>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr tank2 = std::make_shared<Tank>(2, 1, BlockPosition(0, 3), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank1->get_id(), tank1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank2->get_id(), tank2));
	tank1->update(240000);
	tank2->update(240000);
	tank1->attack(2); // notar que tank2 esta fuera de rango. tank1 tiene que acercarse
	tank1->update(0); // no necesita tiempo para setear target
	TEST_CHECK(tank1->get_state() == chasing);
	tank1->update(200);
	TEST_CHECK(tank1->get_position() == BlockPosition(2, 1));
	TEST_CHECK(tank1->get_state() == attacking);
	tank1->update(1000);
	TEST_CHECK(tank2->get_hp() == 23);
}

void test_attack_and_chase(void)
{
	TerrainMap map(4, 5);
	std::map<unsigned int, TeamablePtr> game_objects;
	UnitPtr tank1 = std::make_shared<Tank>(1, 2, BlockPosition(3, 0), map, game_objects, 1);
	UnitPtr tank2 = std::make_shared<Tank>(2, 1, BlockPosition(1, 2), map, game_objects, 1);
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank1->get_id(), tank1));
	game_objects.insert(std::pair<unsigned int, TeamablePtr>(tank2->get_id(), tank2));
	tank1->update(240000);
	tank2->update(240000);
	tank1->attack(2);
	tank2->move_to(BlockPosition(0, 3));
	tank1->update(0);
	tank2->update(0);
	TEST_CHECK(tank1->get_state() == attacking);
	TEST_CHECK(tank2->get_state() == moving);
	tank1->update(200); // tank1 usa estos 200ms para recargar el arma
	tank2->update(200);
	TEST_CHECK(tank2->changed_position());
	tank1->update(0); // tank1 se entera que tank2 se fue de rango asi que empieza a perseguirlo
	TEST_CHECK(tank1->get_state() == chasing);
	tank1->update(200);
	TEST_CHECK(tank1->get_position() == BlockPosition(2, 1));
	TEST_CHECK(tank1->get_state() == attacking);
	tank1->update(800); // ya habia estado 200ms recargando el arma
	TEST_CHECK(tank2->get_hp() == 23);
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
	{NULL, NULL}
};