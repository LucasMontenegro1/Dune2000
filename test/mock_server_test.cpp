//
// Created by ignat on 05/06/22.
//

#include "acutest.h"
#include "../src/Server/mock_server.h"

void test_mock_server(void)
{
	MockServer srv;
	srv.create_unit(70, 59);
	int id = srv.get_state().front().id;
	srv.move_unit(id, 70, 61);
	srv.update();
	struct RawUnit unit = srv.get_state().front();

	TEST_CHECK(unit.row == 69);
	TEST_CHECK(unit.col == 59);
	TEST_CHECK(unit.changed);
	TEST_CHECK(unit.facing_row == 68);
	TEST_CHECK(unit.state == "moving");
}

TEST_LIST = {
	{"main_test", test_mock_server},
	{NULL, NULL}
};