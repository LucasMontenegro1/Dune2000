//
// Created by ignat on 05/06/22.
//

#ifndef DUNE2000_MOCKSERVER_H
#define DUNE2000_MOCKSERVER_H

#include "control_unit.h"
#include <vector>
#include <string>

typedef std::vector<std::pair<unsigned int, unsigned int>> Cliffs;

struct RawUnit {
	int id;
	unsigned int row;
	unsigned int col;
	bool changed;
	unsigned int facing_row;
	unsigned int facing_col;
	std::string state;
};

class MockServer {
	ControlUnit cu;

	Terrains terrains;

	public:
	MockServer();

	/*
	 * Mapa solo contiene arena y acantilados (sand y cliffs)
	 */
	Cliffs get_map() const;

	void create_unit(unsigned int row, unsigned int col);

	void move_unit(int id, unsigned int row_dst, unsigned int col_dst);

	void update();

	std::vector<struct RawUnit> get_state() const;

	~MockServer();
};

#endif //DUNE2000_MOCKSERVER_H
