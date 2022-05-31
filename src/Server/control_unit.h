//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_CONTROL_UNIT_H
#define DUNE2000_CONTROL_UNIT_H

#include "../Model/terrain_map.h"
#include "../Model/model_unit.h"
#include "task.h"
#include "task_resolver.h"
#include <vector>
#include <map>
#include <memory>

class ControlUnit {
	TerrainMap map;

	std::map<int, ModelUnit> units;

	int id_counter;

	TaskResolver task_resolver;

	public:
	ControlUnit(unsigned int rows, unsigned int cols);

	//void set_terrains(const Terrains &terrains);

	void create(BlockPosition initial_pos);

	void move(int id, BlockPosition destination);

	void update();

	std::vector<ModelUnit> get_state() const;

	~ControlUnit();
};

#endif //DUNE2000_CONTROL_UNIT_H
