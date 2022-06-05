//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_CONTROL_UNIT_H
#define DUNE2000_CONTROL_UNIT_H

#include "../Model/terrain_map.h"
#include "../Model/movable.h"
#include <vector>
#include <map>

typedef std::vector<std::pair<BlockPosition, BlockTerrain>> Terrains;

class ControlUnit {
	TerrainMap map;

	std::map<int, Movable> units;

	int id_counter;

	public:
	ControlUnit(unsigned int rows, unsigned int cols);

	void set_terrains(const Terrains &terrains);

	unsigned int units_count() const;

	void create(BlockPosition initial_pos);

	void move(int id, BlockPosition destination);

	void update();

	std::vector<Movable> get_state() const;

	~ControlUnit();
};

#endif //DUNE2000_CONTROL_UNIT_H
