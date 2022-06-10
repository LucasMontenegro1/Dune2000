//
// Created by ignat on 09/06/22.
//

#include "teamable.h"

Teamable::Teamable(unsigned int id_, unsigned int player_id_, unsigned int start_hp) :
id(id_),
player_id(player_id_),
hp(start_hp){}

void Teamable::reduce_hp(unsigned int dmg)
{
	if (dmg >= this->hp)
		this->hp = 0;
	else
		this->hp -= dmg;
}

void Teamable::destroy()
{
	this->hp = 0;
}

bool Teamable::is_dead() const
{
	return this->hp == 0;
}

unsigned int Teamable::get_id() const
{
	return this->id;
}

unsigned int Teamable::get_player_id() const
{
	return this->player_id;
}

unsigned int Teamable::get_hp() const
{
	return this->hp;
}

Teamable::~Teamable() = default;

/*
Teamable::Teamable(Teamable &&other) :
id(other.id),
player_id(other.player_id),
hp(other.hp),
class_id(other.class_id),
type_id(other.type_id)
{
	other.id = INVALID_ID;
	other.player_id = INVALID_ID;
	other.hp = 0;
	other.class_id = INVALID_ID;
	other.type_id = INVALID_ID;
}

Teamable &Teamable::operator=(Teamable &&other)
{
	if (this == &other)
		return *this;

	this->id = other.id;
	this->player_id = other.player_id;
	this->hp = other.hp;
	this->class_id = other.class_id;
	this->type_id = other.type_id;

	other.id = INVALID_ID;
	other.player_id = INVALID_ID;
	other.hp = 0;
	other.class_id = INVALID_ID;
	other.type_id = INVALID_ID;
}
 */