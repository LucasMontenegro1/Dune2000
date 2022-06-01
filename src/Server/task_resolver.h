//
// Created by ignat on 31/05/22.
//

#ifndef DUNE2000_TASK_RESOLVER_H
#define DUNE2000_TASK_RESOLVER_H

#include "task.h"
#include "../Model/model_unit.h"
#include "../Model/terrain_map.h"
#include <memory>



class TaskResolver {
	const TerrainMap &map;

	std::map<int, ModelUnit> &units;

	std::vector<std::shared_ptr<Task>> tasks;

	int &id_counter;

	public:
	TaskResolver(const TerrainMap &map_, std::map<int, ModelUnit> &units_, int &counter);

	void push_task(std::shared_ptr<Task> task);

	void perform_tasks();

	int create_unit(BlockPosition pos);

	int move_unit(int id, BlockPosition pos);
};

#endif //DUNE2000_TASK_RESOLVER_H
