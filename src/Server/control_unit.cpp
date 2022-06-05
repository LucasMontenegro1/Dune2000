//
// Created by ignat on 30/05/22.
//

#include "control_unit.h"
#include <limits>


ControlUnit::ControlUnit(unsigned int rows, unsigned int cols) :
map(rows, cols),
id_counter(std::numeric_limits<int>::min()){}

void ControlUnit::set_terrains(const Terrains &terrains)
{
	for (auto const &it : terrains) {
		if (not this->map.invalid_position(it.first))
			this->map.change_terrain(it.first, it.second);
	}
}

unsigned int ControlUnit::units_count() const
{
	return this->units.size();
}

void ControlUnit::create(BlockPosition initial_pos)
{
	if (this->map.invalid_position(initial_pos))
		return;

	Movable unit(this->id_counter, initial_pos, this->map);
	if (not unit.can_traverse(this->map.at(initial_pos)))
		return;

	this->units.insert(std::pair<int, Movable>(unit.get_id(), unit));
	this->id_counter++;
}

void ControlUnit::move(int id, BlockPosition dst)
{
	if (this->units.count(id) == 0)
		return;
	if (this->map.invalid_position(dst))
		return;

	this->units.at(id).move_to(dst);
}

void ControlUnit::update()
{
	for (auto &it : this->units)
		it.second.act();
}

std::vector<Movable> ControlUnit::get_state() const
{
	std::vector<Movable> tmp_units;
	for (auto const &it : this->units)
		tmp_units.push_back(it.second);

	return tmp_units;
}

ControlUnit::~ControlUnit() = default;