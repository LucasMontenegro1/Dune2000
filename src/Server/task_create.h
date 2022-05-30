//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_TASK_CREATE_H
#define DUNE2000_TASK_CREATE_H

#include "./task.h"
#include "./mock_server.h"

class TaskCreate : public Task {
	BlockPosition pos;
	public:
	TaskCreate(BlockPosition pos_);

	int perform_task(ControlUnit *cu) const override;

	bool has_next() const override;

	virtual std::shared_ptr<Task> get_next() const;

	virtual ~TaskCreate();
};

#endif //DUNE2000_TASK_CREATE_H
