//
// Created by ignat on 30/05/22.
//

#include "control_unit.h"
#include "task_create.h"
#include "task_move.h"
#include <limits>

ControlUnit::ControlUnit(unsigned int rows, unsigned int cols) :
map(rows, cols),
units(),
id_counter(std::numeric_limits<int>::min()),
task_resolver(map, units, id_counter){}

void ControlUnit::create(BlockPosition initial_pos)
{
	if (this->map.invalid_position(initial_pos))
		return;

	std::shared_ptr<Task> task = std::make_shared<TaskCreate>(initial_pos);
	this->task_resolver.push_task(task);
}

void ControlUnit::move(int id, BlockPosition dst)
{
	if (this->units.count(id) == 0)
		return;
	if (this->map.invalid_position(dst))
		return;

	const ModelUnit &unit = this->units.at(id);
	std::vector<BlockPosition> path = this->map.get_path(unit.get_pos(), dst, unit.get_mobility());

	if (not path.empty()) {
		std::shared_ptr<Task> task = std::make_shared<TaskMove>(id, path);
		this->task_resolver.push_task(task);
	}
}

void ControlUnit::update()
{
	this->task_resolver.perform_tasks();
}

std::vector<ModelUnit> ControlUnit::get_state() const
{
	std::vector<ModelUnit> tmp_units;
	for (auto const &it : this->units)
		tmp_units.push_back(it.second);

	return tmp_units;
}

ControlUnit::~ControlUnit() = default;