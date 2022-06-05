//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_MOVABLE_H
#define DUNE2000_MOVABLE_H

#include "terrain_map.h"
#include <vector>

enum MovableState {
	neutral,
	moving
};

class Movable {
	int id;
	BlockPosition pos;
	const TerrainMap &map;
	MovableState state;
	bool changed;
	std::vector<BlockPosition> path;

	public:
	Movable(int id_, BlockPosition pos_, const TerrainMap &map_);

	void act();

	bool can_traverse(BlockTerrain terrain) const;

	void move_to(BlockPosition destination);

	bool is_at_position(BlockPosition position) const;

	int get_id() const;

	bool has_changed() const;

	~Movable();

	Movable(const Movable &other);
	Movable &operator=(const Movable &other);
};

#endif //DUNE2000_MOVABLE_H
