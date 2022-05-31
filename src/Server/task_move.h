//
// Created by ignat on 31/05/22.
//

#ifndef DUNE2000_TASK_MOVE_H
#define DUNE2000_TASK_MOVE_H

#include "task.h"
#include "../Model/block_position.h"
#include <vector>

class TaskMove : public Task {
	int id;

	std::vector<BlockPosition> path;

	public:
	TaskMove(int id_, std::vector<BlockPosition> &path_);

	virtual int perform_task(TaskResolver *tr);

	virtual bool has_next() const;

	virtual ~TaskMove();
};

#endif //DUNE2000_TASK_MOVE_H
