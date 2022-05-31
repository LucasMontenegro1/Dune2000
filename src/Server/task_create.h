//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_TASK_CREATE_H
#define DUNE2000_TASK_CREATE_H

#include "./task.h"
#include "../Model/block_position.h"

class TaskCreate : public Task {
	BlockPosition pos;
	public:
	TaskCreate(BlockPosition pos_);

	int perform_task(TaskResolver *tr) override;

	bool has_next() const override;

	virtual ~TaskCreate();
};

#endif //DUNE2000_TASK_CREATE_H
