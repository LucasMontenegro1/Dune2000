//
// Created by ignat on 19/05/22.
//

#ifndef DUNE2000_FREMEN_MOVILITY_H
#define DUNE2000_FREMEN_MOVILITY_H

#include "./unit_movility.h"

class FremenMovility : public UnitMovility {
	public:
	virtual bool can_traverse(BlockTerrain terrain) const override;
};

#endif //DUNE2000_FREMEN_MOVILITY_H
