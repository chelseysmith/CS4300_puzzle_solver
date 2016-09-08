#include "State.h"

State::State(unsigned int grid_size, std::vector<std::vector<int>> tiles):
	m_grid_size(grid_size),
	m_tiles(tiles)
{
}


State::~State()
{
}

unsigned int State::Get_grid_size()
{
	return m_grid_size;
}

std::vector<std::vector<int>> State::Get_tiles()
{
	return m_tiles;
}

void State::Set_tile(int m, int n, int value)
{
	m_tiles[m][n] = value;
}
