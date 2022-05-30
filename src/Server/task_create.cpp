//
// Created by ignat on 30/05/22.
//

#include "task_create.h"

TaskCreate::TaskCreate(BlockPosition pos_) :
pos(pos_){}

int TaskCreate::perform_task(ControlUnit *cu) const
{
	return cu->create_unit(this->pos);
}

bool TaskCreate::has_next() const
{
	return false;
}

std::shared_ptr <Task> TaskCreate::get_next() const
{
	throw std::out_of_range("Invalid operation\n");
}

TaskCreate::~TaskCreate() noexcept = default;