//
// Created by ignat on 30/05/22.
//

#ifndef DUNE2000_TASK_H
#define DUNE2000_TASK_H

#include <memory>

class TaskResolver;

class Task {
	public:
	virtual int perform_task(TaskResolver *tr) = 0;

	virtual bool has_next() const = 0;

	virtual ~Task() = default;
};

#endif //DUNE2000_TASK_H
