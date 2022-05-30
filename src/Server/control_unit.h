//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_CONTROL_UNIT_H
#define DUNE2000_CONTROL_UNIT_H

#include "../Model/terrain_map.h"
#include "../Model/block_position.h"
#include "../Model/block_terrain.h"
#include "./model_unit.h"
#include "./task.h"
#include <vector>
#include <map>
#include <utility>
#include <memory>

typedef std::vector<std::pair<BlockPosition, BlockTerrain>> Terrains;

class ControlUnit {
	TerrainMap map;

	std::map<int, ModelUnit> units;

	std::vector<std::shared_ptr<Task>> tasks;

	int id_counter;

	public:
	ControlUnit(unsigned int rows, unsigned int cols);

	//void set_terrains(const Terrains &terrains);

	void push_task(std::shared_ptr<Task> task);

	void update();

	std::vector<ModelUnit> get_state() const;

	~ControlUnit();

	int create_unit(BlockPosition pos);

	//int move_unit(int id, BlockPosition pos);
};

#endif //DUNE2000_CONTROL_UNIT_H
