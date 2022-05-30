//
// Created by ignat on 30/05/22.
//

#include "./acutest.h"
#include "../src/Server/control_unit.h"
#include "../src/Server/task_create.h"

void test_create_unit(void)
{
	ControlUnit cu(14, 20);
	std::shared_ptr<Task> task1 = std::make_shared<TaskCreate>(BlockPosition(0, 0));
	std::shared_ptr<Task> task2 = std::make_shared<TaskCreate>(BlockPosition(14, 20));
	cu.push_task(task1);
	cu.push_task(task2);
	cu.update();

	std::vector<ModelUnit> units = cu.get_state();

	TEST_CHECK(units.size() == 1);
	TEST_CHECK(units.front().get_pos() == BlockPosition(0, 0));
}

TEST_LIST = {
	{"create_unit", test_create_unit},
	{NULL, NULL}
};
