//
// Created by ignat on 19/05/22.
//

#include "./acutest.h"
#include "../src/Model/block_terrain.h"
#include "../src/Model/fremen_mobility.h"

void test_fremen_mobility(void)
{
	FremenMobility mobility;

	TEST_CHECK(mobility.can_traverse(sand));
	TEST_CHECK(mobility.can_traverse(dunes));
	TEST_CHECK(mobility.can_traverse(rock));
	TEST_CHECK(mobility.can_traverse(peaks));
	TEST_CHECK(!mobility.can_traverse(cliffs));
}

TEST_LIST = {
	{"fremen_mobility", test_fremen_mobility},
	{NULL, NULL}
};