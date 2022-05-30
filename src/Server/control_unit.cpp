//
// Created by ignat on 30/05/22.
//

#include "control_unit.h"
#include <limits>

const int SUCCESS = 0;
const int FAILURE = 1;

ControlUnit::ControlUnit(unsigned int rows, unsigned int cols) :
map(rows, cols),
id_counter(std::numeric_limits<int>::min()){}

void ControlUnit::push_task(std::shared_ptr<Task> task)
{
	this->tasks.push_back(task);
}

void ControlUnit::update()
{
	std::vector<std::shared_ptr<Task>> remaining_tasks;

	for (auto const &task : this->tasks) {
		int s = task->perform_task(this);
		if (s == SUCCESS and task->has_next())
			remaining_tasks.push_back(task->get_next());
	}

	this->tasks = remaining_tasks;
}

std::vector<ModelUnit> ControlUnit::get_state() const
{
	std::vector<ModelUnit> tmp_units;
	for (auto const &it : this->units)
		tmp_units.push_back(it.second);

	return tmp_units;
}

ControlUnit::~ControlUnit() = default;

int ControlUnit::create_unit(BlockPosition pos)
{
	if (this->map.invalid_position(pos))
		return FAILURE;

	ModelUnit unit(pos, this->id_counter);
	this->id_counter++;
	this->units.insert(std::pair<int, ModelUnit>(unit.get_id(), unit));
	return SUCCESS;
}