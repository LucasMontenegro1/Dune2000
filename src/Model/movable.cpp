//
// Created by ignat on 30/05/22.
//

#include "movable.h"
#include "infantry_mobility.h"

Movable::Movable(int id_, BlockPosition pos_, const TerrainMap &map_) :
id(id_),
pos(pos_),
map(map_),
state(neutral),
changed(true)
{
	if (this->map.invalid_position(this->pos))
		throw std::out_of_range("Movable::Movable : Invalid position\n");
}

void Movable::act()
{
	if (this->state == moving) {
		BlockPosition next_pos = this->path.back();
		if (this->can_traverse(this->map.at(next_pos))) {
			this->pos = next_pos;
			this->path.pop_back();
			if (this->path.empty())
				this->state = neutral;
		} else {
			this->state = neutral;
		}
		this->changed = true;
	} else {
		this->changed = false;
	}
}

bool Movable::can_traverse(BlockTerrain terrain) const
{
	/*
	 * Por ahora uso este default
	 */
	InfantryMobility mob;
	return mob.can_traverse(terrain);
}

void Movable::move_to(BlockPosition dst)
{
	if (this->map.invalid_position(dst))
		return;

	InfantryMobility mob;
	this->path = this->map.get_path(this->pos, dst, mob);
	if (this->path.size() >= 2) {
		this->path.pop_back(); // La primer posicion es la posicion actual
		this->state = moving;
	} else {
		this->state = neutral;
	}
}

bool Movable::is_at_position(BlockPosition position) const
{
	return this->pos == position;
}

BlockPosition Movable::get_pos() const
{
	return this->pos;
}

BlockPosition Movable::facing_pos() const
{
	if (this->state == neutral)
		return this->pos;
	else
		return this->path.back();
}

int Movable::get_id() const
{
	return this->id;
}

MovableState Movable::get_state() const
{
	return this->state;
}

bool Movable::has_changed() const
{
	return this->changed;
}

Movable::~Movable() = default;

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