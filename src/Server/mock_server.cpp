//
// Created by ignat on 05/06/22.
//

#include "mock_server.h"

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

void MockServer::create_unit(unsigned int row, unsigned int col)
{
	BlockPosition pos(row, col);
	this->cu.create(pos);
}

void MockServer::move_unit(int id, unsigned int row_dst, unsigned int col_dst)
{
	BlockPosition dst(row_dst, col_dst);
	this->cu.move(id, dst);
}

void MockServer::update()
{
	this->cu.update();
}

std::vector<struct RawUnit> MockServer::get_state() const
{
	std::vector<Movable> units = this->cu.get_state();
	std::vector<RawUnit> raw_units;
	struct RawUnit unit;
	for (auto const &it : units) {
		unit.id = it.get_id();
		unit.row = it.get_pos().row();
		unit.col = it.get_pos().col();
		unit.changed = it.has_changed();
		unit.facing_row = it.facing_pos().row();
		unit.facing_col = it.facing_pos().col();
		MovableState state = it.get_state();
		if (state == neutral)
			unit.state = "neutral";
		else
			unit.state = "moving";
		raw_units.push_back(unit);
	}
	return raw_units;
}

MockServer::~MockServer() = default;
