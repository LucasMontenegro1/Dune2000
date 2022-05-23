//
// Created by ignat on 19/05/22.
//

#include "./fremen_mobility.h"

bool FremenMobility::can_traverse(BlockTerrain terrain) const
{
	return terrain != cliffs;
}