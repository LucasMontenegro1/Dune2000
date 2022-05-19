//
// Created by ignat on 19/05/22.
//

#include "block_position.h"

BlockPosition::BlockPosition(unsigned int row, unsigned int col) :
pos(row, col){}

unsigned int BlockPosition::row() const
{
	return this->pos.real();
}

unsigned int BlockPosition::col() const
{
	return this->pos.imag();
}

double BlockPosition::distance_to(const BlockPosition &other) const
{
	return std::abs(this->pos - other.pos);
}

bool BlockPosition::operator==(const BlockPosition &other) const
{
	bool eq_real = this->pos.real() == other.pos.real();
	bool eq_img = this->pos.imag() == other.pos.imag();
	return eq_real && eq_img;
}

bool BlockPosition::operator!=(const BlockPosition &other) const
{
	return !(*this == other);
}

BlockPosition::BlockPosition(const BlockPosition &other) :
pos(other.pos){}

BlockPosition& BlockPosition::operator=(const BlockPosition &other)
{
	if (this == &other)
		return *this;

	this->pos = other.pos;
	return *this;
}

BlockPosition::~BlockPosition() = default;