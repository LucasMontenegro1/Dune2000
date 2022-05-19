//
// Created by ignat on 19/05/22.
//

#include "./acutest.h"
#include "../src/block_terrain.h"
#include "../src/fremen_movility.h"

void test_fremen_movility_on_sand(void)
{
	BlockTerrain terrain = sand;
	FremenMovility movility;

	TEST_CHECK(movility.can_traverse(terrain));
}

TEST_LIST = {
	{"fremen_movility_on_sand", test_fremen_movility_on_sand},
	{NULL, NULL}
};