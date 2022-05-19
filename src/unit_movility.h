//
// Created by ignat on 19/05/22.
//

#ifndef DUNE2000_UNIT_MOVILITY_H
#define DUNE2000_UNIT_MOVILITY_H

#include "./block_terrain.h"

class UnitMovility {
	public:
	virtual bool can_traverse(BlockTerrain terrain) const = 0;
};

#endif //DUNE2000_UNIT_MOVILITY_H
