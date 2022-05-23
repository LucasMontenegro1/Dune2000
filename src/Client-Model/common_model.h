#ifndef COMMON_MODEL_H
#define COMMON_MODEL_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_units.h"
#include "common_grounds.h"

class Model {
	std::vector<Unit*> units;
	std::vector<Ground*> grounds;
	bool one_unit_can_moves;

	void deleteUnits();
	
	void deleteGrounds();

	public:
	Model(std::vector<Unit*> &units, std::vector<Ground*> &grounds);
	
	void update_status(std::vector<Unit*> &units, std::vector<Ground*> &grounds);
	
	Unit get_unit(int cordX, int cordY);
	
	Unit get_unit_can_moves();
	
	bool a_unit_can_moves();
	
	void unit_enable_move(int unit_id);
	
	bool is_unit_there(int cordX, int cordY);

	bool is_ground_there(int cordX, int cordY);
	
	int get_grounds_size();
	
	int get_units_size();
	
	std::vector<Ground*> get_grounds();
	
	std::vector<Units*> get_units();
	
}
#endif
