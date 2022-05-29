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
	
	bool have_unit(Unit &unit);

	public:
	Model(std::vector<Unit*> &units, std::vector<Ground*> &grounds);
	
	void update_status(std::vector<Unit*> &units);
	
	int get_y_size();
	
	int get_x_size();
	
	Unit get_unit(int cordX, int cordY);
	
	Unit get_unit_can_moves();
	
	bool a_unit_can_moves();
	
	void unit_enable_move(int unit_id);
	
	bool is_unit_there(float cordX, float cordY);
	
	int get_grounds_size();
	
	int get_units_size();
	
	std::vector<Ground*> get_grounds();
	
	std::vector<Units*> get_units();
	
	~Model();
	
}
#endif
