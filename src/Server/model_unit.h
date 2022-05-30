//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_MODEL_UNIT_H
#define DUNE2000_MODEL_UNIT_H

#include "../Model/block_position.h"
#include <string>

enum UnitState {
	neutral,
	moving
};

class ModelUnit {
	BlockPosition pos;
	UnitState state;
	int id;

	public:
	ModelUnit(BlockPosition starting_pos, int id_);

	void move_to(BlockPosition next_pos);
	void change_state(UnitState new_state);

	BlockPosition get_pos() const;
	UnitState get_state() const;
	int get_id() const;

	~ModelUnit();

	ModelUnit(const ModelUnit &other);
	ModelUnit &operator=(const ModelUnit &other);
};

#endif //DUNE2000_MODEL_UNIT_H
