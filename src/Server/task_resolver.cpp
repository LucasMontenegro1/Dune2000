//
// Created by ignat on 31/05/22.
//

#include "task_resolver.h"

const int SUCCESS = 0;
const int FAILURE = 1;

TaskResolver::TaskResolver(const TerrainMap &map_, std::map<int, ModelUnit> &units_, int &counter) :
map(map_),
units(units_),
id_counter(counter){}

void TaskResolver::push_task(std::shared_ptr<Task> task)
{
	this->tasks.push_back(task);
}

void TaskResolver::perform_tasks()
{
	std::vector<std::shared_ptr<Task>> remaining_tasks;

	for (auto const &task : this->tasks) {
		int s = task->perform_task(this);
		if (s == SUCCESS and task->has_next())
			remaining_tasks.push_back(task);
	}

	this->tasks = remaining_tasks;
}

int TaskResolver::create_unit(BlockPosition pos)
{
	if (this->map.invalid_position(pos))
		return FAILURE;

	ModelUnit unit(pos, this->id_counter);
	this->id_counter++;
	this->units.insert(std::pair<int, ModelUnit>(unit.get_id(), unit));
	return SUCCESS;
}

int TaskResolver::move_unit(int id, BlockPosition pos)
{
	/*
	 * No es necesario chequear que la posicion sea
	 * valida ya que se supone ya se chequeo
	 */
	if (this->units.count(id) == 0)
		return FAILURE;

	ModelUnit &unit = this->units.at(id);
	if (not unit.can_traverse(this->map.at(pos)))
		return FAILURE;

	unit.move_to(pos);
	return SUCCESS;
}
