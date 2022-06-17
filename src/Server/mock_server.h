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
	unsigned int id;
	unsigned int player_id;
	unsigned int type_id;
	unsigned int weapon_id;
	unsigned int hp;
	unsigned int row;
	unsigned int col;
	unsigned int facing_row;
	unsigned int facing_col;
	unsigned int target_id;
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

	void create_unit(unsigned int player_id, unsigned int type_id, unsigned int row, unsigned int col);

	void move_unit(unsigned int id, unsigned int row_dst, unsigned int col_dst);

	void unit_attack(unsigned int id, unsigned int target_id);

	void update(unsigned int time_delta);

	std::vector<struct RawUnit> get_state() const;

	~MockServer();
};

#endif //DUNE2000_MOCKSERVER_H
