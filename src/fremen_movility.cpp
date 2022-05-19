//
// Created by ignat on 19/05/22.
//

#include "./fremen_movility.h"

bool FremenMovility::can_traverse(BlockTerrain terrain) const
{
	return terrain != cliffs;
}