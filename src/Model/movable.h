//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_MOVABLE_H
#define DUNE2000_MOVABLE_H

#include "teamable.h"
#include "terrain_map.h"
#include <vector>
#include <map>
#include <memory>

typedef unsigned int uint;
typedef std::shared_ptr<Teamable> TeamablePtr;

enum MovableState {
	neutral,
	autoattack,
	moving
};

class Movable : public Teamable {
	BlockPosition pos;
	const TerrainMap &map;
	MovableState state;
	bool changed_pos;
	std::vector<BlockPosition> path;
	std::map<uint, TeamablePtr> &units;

	public:
	Movable(uint id_, uint player_id_, uint start_hp, BlockPosition pos_,
		const TerrainMap &map_, std::map<uint, TeamablePtr> &units_);

	void act();
	void move_to(BlockPosition destination);

	virtual unsigned int distance_to(BlockPosition position) const override;

	virtual std::vector<BlockPosition> positions_at_range(unsigned short int range) const override;

	/*
	 * Devuelve true si la unidad se movio en el
	 * ultimo act()
	 */
	virtual bool changed_position() const override;

	virtual bool can_traverse(BlockTerrain terrain) const = 0;
	virtual const UnitMobility &get_mobility() const = 0;

	BlockPosition get_pos() const;
	MovableState get_state() const;
	BlockPosition facing_pos() const;
	virtual unsigned int get_class_id() const = 0;
	virtual unsigned int get_type_id() const = 0;

	virtual ~Movable();

	Movable(const Movable &other) = delete;
	Movable &operator=(const Movable &other) = delete;
	Movable(Movable &&other) = delete;
	Movable &operator=(Movable &&other) = delete;

	private:
	void act_moving();
};

#endif //DUNE2000_MOVABLE_H
