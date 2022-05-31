//
// Created by ignat on 31/05/22.
//

#include "task_move.h"
#include "task_resolver.h"

TaskMove::TaskMove(int id_, std::vector <BlockPosition> &path_) :
id(id_),
path(std::move(path_)){}

int TaskMove::perform_task(TaskResolver *tr)
{
	if (this->path.empty())
		throw std::logic_error("No path\n");

	int s = tr->move_unit(this->id, this->path.back());
	this->path.pop_back();
	return s;
}

bool TaskMove::has_next() const
{
	return not this->path.empty();
}

TaskMove::~TaskMove() noexcept = default;


