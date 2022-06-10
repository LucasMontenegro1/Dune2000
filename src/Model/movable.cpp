//
// Created by ignat on 30/05/22.
//

#include "movable.h"

Movable::Movable(unsigned int id_, unsigned int player_id_, unsigned int start_hp,
		 BlockPosition pos_, const TerrainMap &map_) :
	Teamable(id_, player_id_, start_hp),
	pos(pos_),
	map(map_),
	state(neutral),
	changed_pos(false)
{
	if (this->map.invalid_position(this->pos))
		throw std::out_of_range("Movable::Movable : Invalid position\n");
}

void Movable::act()
{
	if (this->state == neutral)
		this->changed_pos = false;
	else if (this->state == moving)
		this->act_moving();
}

void Movable::act_moving()
{
	BlockPosition next_pos = this->path.back();
	if (this->can_traverse(this->map.at(next_pos))) {
		this->pos = next_pos;
		this->changed_pos = true;
		this->path.pop_back();
		if (this->path.empty())
			this->state = neutral;
	} else {
		this->changed_pos = false;
		this->state = neutral;
	}
}

void Movable::move_to(BlockPosition dst)
{
	if (this->map.invalid_position(dst))
		return;

	const UnitMobility &mob = this->get_mobility();
	this->path = this->map.get_path(this->pos, dst, mob);
	if (this->path.size() >= 2) {
		this->path.pop_back(); // La primer posicion es la posicion actual
		this->state = moving;
	} else {
		this->state = neutral;
	}
}

unsigned int Movable::distance_to(BlockPosition position) const
{
	return this->pos.distance_to(position);
}

std::vector<BlockPosition> Movable::positions_at_range(unsigned short int range) const
{
	std::vector<BlockPosition> positions;
	unsigned int row = this->pos.row();
	unsigned int col = this->pos.col();

	int x, y;
	for (x = -range; x <= range; x++) {
		for (y = -range; y <= range; y++) {
			BlockPosition position(row + x, col + y);
			if (not this->map.invalid_position(position)
			and this->pos.distance_to(position) <= range)
				positions.push_back(position);
		}
	}

	return positions;
}

bool Movable::changed_position() const
{
	return this->changed_pos;
}


BlockPosition Movable::get_pos() const
{
	return this->pos;
}

MovableState Movable::get_state() const
{
	return this->state;
}

BlockPosition Movable::facing_pos() const
{
	if (this->state == neutral)
		return this->pos;
	else
		return this->path.back();
}

Movable::~Movable() = default;

/*
Movable::Movable(const Movable &other) :
id(other.id),
pos(other.pos),
map(other.map),
state(other.state),
changed(other.changed),
path(other.path){}

Movable &Movable::operator=(const Movable &other)
{
	if (this == &other)
		return *this;

	this->id = other.id;
	this->pos = other.pos;
	this->state = other.state;
	this->changed = other.changed;
	this->path = other.path;

	return *this;
}
 */