#pragma once
#include <vector>

class State
{
public:
	State(unsigned int grid_size, std::vector<std::vector<int>> tiles);
	~State();

	unsigned int Get_grid_size();
	std::vector<std::vector<int>> Get_tiles();
	void Set_tile(int m, int n, int value);

private:
	unsigned int m_grid_size;
	std::vector<std::vector<int>> m_tiles;
};

