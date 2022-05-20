//
// Created by ignat on 19/05/22.
//

#include "./terrain_map.h"
#include <queue>
#include <stdexcept>

#define DEFAULT_VALUE sand

TerrainMap::TerrainMap(unsigned int rows_, unsigned int cols_)
{
	this->rows = rows_;
	this->cols = cols_;

	this->map = (BlockTerrain **) malloc(this->rows * sizeof(BlockTerrain *));
	for (unsigned int i = 0; i < this->rows; i++) {
		this->map[i] = (BlockTerrain *) malloc(this->cols * sizeof(BlockTerrain));
		for (unsigned int j = 0; j < this->cols; j++)
			this->map[i][j] = DEFAULT_VALUE;
	}
}

std::list<BlockPosition>
TerrainMap::get_path(BlockPosition org, BlockPosition dst, const UnitMovility *mov) const
{
	this->validate_positions(org, dst);

	std::priority_queue<PathNode> nodes;
	std::map<BlockPosition, PathNode> visited;
	bool found_path = false;
	PathNode node(org, org, 0, dst);
	node.set_as_origin();
	nodes.push(node);

	while (!nodes.empty()) {
		node = nodes.top();
		if (node.get_pos() == dst) {
			visited.insert(std::pair<BlockPosition, PathNode>(node.get_pos(), node));
			found_path = true;
			break;
		}
		if (this->already_visited(node.get_pos(), visited)) {
			nodes.pop();
			continue;
		}
		std::list<BlockPosition> neighbours = this->get_neighbours(node.get_pos(), mov);
		for (auto const &it : neighbours) {
			if (!this->already_visited(it, visited))
				nodes.push(PathNode(it, node, dst));
		}
		visited.insert(std::pair<BlockPosition, PathNode>(node.get_pos(), node));
		nodes.pop();
	}

	if (found_path)
		return this->build_path(visited, dst);
	else
		return std::list<BlockPosition>();
}

BlockTerrain TerrainMap::at(BlockPosition pos) const
{
	if (this->invalid_position(pos))
		throw std::out_of_range("Invalid position\n");

	return this->map[pos.row()][pos.col()];
}

TerrainMap::~TerrainMap()
{
	for (unsigned int i = 0; i < this->rows; i++)
		free(this->map[i]);
	free(this->map);
}

bool TerrainMap::invalid_position(BlockPosition pos) const
{
	bool invalid = pos.row() >= this->rows;
	invalid = invalid or pos.col() >= this->cols;

	return invalid;
}

void TerrainMap::validate_positions(BlockPosition org, BlockPosition dst) const
{
	if (this->invalid_position(org))
		throw std::out_of_range("Invalid origin\n");
	if (this->invalid_position(dst))
		throw std::out_of_range("Invalid destination\n");
}

bool TerrainMap::already_visited(BlockPosition pos, const std::map<BlockPosition, PathNode>& visited) const
{
	auto const &it = visited.find(pos);
	return it != visited.end();
}

std::list<BlockPosition>
TerrainMap::get_neighbours(BlockPosition pos, const UnitMovility *mov) const
{
	std::list<BlockPosition> neighbours;
	unsigned int x, y;
	for (short int i = 0; i < 8; i++) {
		/*
		 * Recorro los 8 bloques vecinos
		 * en sentido horario empezando
		 * por las 12
		 */
		x = i % 4 == 0 ? 0 : 1;
		x *= i <= 4 ? 1 : -1;
		y = i % 4 == 2 ? 0 : 1;
		y *= i <= 2 or i >= 6 ? 1 : -1;

		BlockPosition neighbour(pos.row() + x, pos.col() + y);
		if (this->invalid_position(neighbour))
			continue;

		if (mov->can_traverse(this->at(neighbour)))
			neighbours.push_back(neighbour);
	}

	return neighbours;
}

std::list<BlockPosition>
TerrainMap::build_path(const std::map<BlockPosition, PathNode> &visited, BlockPosition dst) const
{
	std::list<BlockPosition> path;
	auto const &it = visited.find(dst);
	PathNode node = it->second;
	path.push_front(node.get_pos());

	while (!node.is_origin()) {
		it = visited(node.get_previous());
		node = it->second;
		path.push_front(node.get_pos());
	}

	return path;
}