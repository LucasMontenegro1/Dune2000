//
// Created by ignat on 05/06/22.
//

#include "acutest.h"
#include "../src/Server/mock_server.h"

void test_move(void)
{
	MockServer srv;
	srv.create_unit(1, 1, 70, 59);
	srv.update(60000);
	unsigned int id = srv.get_state().front().id;
	srv.move_unit(id, 70, 61);
	srv.update(450);
	struct RawUnit unit = srv.get_state().front();

	TEST_CHECK(unit.row == 69);
	TEST_CHECK(unit.col == 59);
	TEST_CHECK(unit.facing_row == 68);
	TEST_CHECK(unit.state == "moving");
}

TEST_LIST = {
	{"move", test_move},
	{NULL, NULL}
};