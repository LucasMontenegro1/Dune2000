//
// Created by ignat on 30/05/22.
//

#include "task_create.h"
#include "task_resolver.h"

TaskCreate::TaskCreate(BlockPosition pos_) :
pos(pos_){}

int TaskCreate::perform_task(TaskResolver *tr)
{
	return tr->create_unit(this->pos);
}

bool TaskCreate::has_next() const
{
	return false;
}

TaskCreate::~TaskCreate() noexcept = default;