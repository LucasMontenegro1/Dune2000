//
// Created by ignat on 05/06/22.
//

#include "mock_server.h"
#include "../Model/unit.h"

typedef std::pair<BlockPosition, BlockTerrain> TerrainPos;

MockServer::MockServer() :
cu(360, 360)
{
	for (unsigned int i = 60; i <= 100; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(i, 60), cliffs));
	for (unsigned int i = 0; i <= 50; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(i, 120), cliffs));
	for (unsigned int i = 50; i <= 60; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(i, 121), cliffs));
	for (unsigned int i = 122; i <= 140; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(61, i), cliffs));
	for (unsigned int i = 0; i <= 50; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(62 + i, 141 + i), cliffs));
	for (unsigned int i = 30; i <= 320; i++)
		this->terrains.push_back(TerrainPos(BlockPosition(i, 250), cliffs));

	this->cu.set_terrains(terrains);
}

Cliffs MockServer::get_map() const
{
	Cliffs cliffs;
	for (auto const &it : this->terrains) {
		std::pair<unsigned int, unsigned> pos(it.first.row(), it.first.col());
		cliffs.push_back(pos);
	}
	return cliffs;
}

void MockServer::create_unit(unsigned int player_id, unsigned int type_id, unsigned int row, unsigned int col)
{
	BlockPosition pos(row, col);
	this->cu.cmd_create(player_id, type_id, pos);
}

void MockServer::move_unit(unsigned int id, unsigned int row_dst, unsigned int col_dst)
{
	BlockPosition dst(row_dst, col_dst);
	this->cu.cmd_move(id, dst);
}

void MockServer::unit_attack(unsigned int id, unsigned int target_id)
{
	this->cu.cmd_attack(id, target_id);
}

void MockServer::update(unsigned int time_delta)
{
	this->cu.update(time_delta);
}

std::vector<struct RawUnit> MockServer::get_state() const
{
	std::vector<shared_ptr<Teamable>> units = this->cu.get_state();
	std::vector<RawUnit> raw_units;
	struct RawUnit raw_unit;
	for (auto const &it : units) {
		shared_ptr<Unit> unit = dynamic_pointer_cast<Unit>(it); // por ahora son todas unidades. Mas adelante con edificio y qcyo va a haber otros tipos
		if (unit->get_state() == creating)
			continue;

		raw_unit.id = unit->get_id();
		raw_unit.player_id = unit->get_player_id();
		raw_unit.type_id = unit->get_type_id();
		raw_unit.weapon_id = unit->get_weapon_id();
		raw_unit.hp = unit->get_hp();
		raw_unit.row = unit->get_position().row();
		raw_unit.col = unit->get_position().col();
		raw_unit.facing_row = unit->facing_position().row();
		raw_unit.facing_col = unit->facing_position().col();
		raw_unit.target_id = unit->target_id();
		if (unit->get_state() == neutral)
			raw_unit.state = "neutral";
		else if (unit->get_state() == autoattacking
		or unit->get_state() == attacking)
			raw_unit.state = "attacking";
		else
			raw_unit.state = "moving";

		raw_units.push_back(raw_unit);
	}
	return raw_units;
}

MockServer::~MockServer() = default;
