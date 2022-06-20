//
// Created by ignat on 16/06/22.
//

#ifndef DUNE2000_ENTITY_FACTORY_H
#define DUNE2000_ENTITY_FACTORY_H

#include "../Model/Map/terrain_map.h"
#include "../Model/Entities/teamable.h"
#include <memory>

typedef std::shared_ptr<Teamable> TeamablePtr;

class EntityFactory {
	TerrainMap &map;
	std::map<unsigned int, TeamablePtr> &entities;
	unsigned int id_counter;

public:
	EntityFactory(TerrainMap &cu_map, std::map<unsigned int, TeamablePtr> &cu_entities);

	void create(unsigned int player_id, unsigned int type_id, BlockPosition position);

	~EntityFactory();

private:
	void mk_linfantry(unsigned int player_id, BlockPosition position);
	void mk_tank(unsigned int player_id, BlockPosition position);
	void mk_trike(unsigned int player_id, BlockPosition position);
};

#endif //DUNE2000_ENTITY_FACTORY_H
