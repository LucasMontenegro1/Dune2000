//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_MODEL_UNIT_H
#define DUNE2000_MODEL_UNIT_H

#include "block_position.h"
#include "infantry_mobility.h"
#include "block_terrain.h"
#include <string>
#include <memory>

class ModelUnit {
	BlockPosition pos;
	InfantryMobility mobility;
	int id;

	public:
	ModelUnit(BlockPosition starting_pos, int id_);

	bool can_traverse(BlockTerrain terrain) const;
	void move_to(BlockPosition next_pos);

	BlockPosition get_pos() const;
	const UnitMobility &get_mobility() const;
	int get_id() const;

	~ModelUnit();

	ModelUnit(const ModelUnit &other);
	ModelUnit &operator=(const ModelUnit &other);
};

#endif //DUNE2000_MODEL_UNIT_H
