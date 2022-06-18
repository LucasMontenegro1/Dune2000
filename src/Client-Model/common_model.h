#ifndef COMMON_MODEL_H
#define COMMON_MODEL_H
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_ground.h"

class Model {
	std::map <int, Unit*> units;
	Ground ground;	
	bool one_unit_can_moves;
	int team;
	
	void deleteUnits();
	
	public:
	Model(std::map <int, Unit*> &units, Ground &grounds, int team);
	
	//void update(std::map <int, Unit*> &units);
	
	int get_y_size();
	
	int get_x_size();

	void move_by_position(int id);
	
	int get_unit(float cordX, float cordY);
	
	std::vector<int> get_units_can_moves();
	
	bool a_unit_can_moves();

	void no_enable_moves();
	
	void unit_enable_move(int unit_id);
	
	bool is_unit_there(float cordX, float cordY);

	bool is_enemy_there(float cordX, float cordY);
	
	int get_units_size();

	int get_team();
	
	Ground &get_grounds();
	
	std::map <int, Unit*> &get_units();
	
	~Model();
	
};
#endif
