//
// Created by ignat on 10/06/22.
//

#ifndef DUNE2000_LIGHT_INFANTRY_H
#define DUNE2000_LIGHT_INFANTRY_H

#include "movable.h"
#include "infantry_mobility.h"

class LightInfantry : public Movable {
	InfantryMobility mob;

	public:
	LightInfantry(uint id_, uint player_id_, BlockPosition pos_, const TerrainMap &map_);

	virtual bool can_traverse(BlockTerrain terrain) const override;
	virtual const UnitMobility &get_mobility() const override;

	virtual unsigned int get_class_id() const override;
	virtual unsigned int get_type_id() const override;

	virtual ~LightInfantry();
};

#endif //DUNE2000_LIGHT_INFANTRY_H
