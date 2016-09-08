#include "Problem.h"


Problem::Problem(State state):
	m_state(state)
{
}


Problem::~Problem()
{
}

std::vector<Action::move> Problem::Actions(State state)
{
	//TODO: Given a state, return a vector of all legal actions
	std::vector<Action::move> moves;

	//FIND THE EMPTY TILE
	int m, n;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			if (state.Get_tiles()[i][j] == -1)
			{
				m = i;
				n = j;
			}
		}
	}

	//CHECK THE LEFT, UP, RIGHT DOWN FROM SAID TILE, IF THEY ARE LEGAL "NOT OUT OF BOUNDS", ADD TO RETURN VECTOR
	//{up, down}
	if (m <= 0)
		moves.push_back(Action::move::up);
	else if(m >= state.Get_grid_size() - 1)
		moves.push_back(Action::move::down);
	else
	{
		moves.push_back(Action::move::up);
		moves.push_back(Action::move::down);
	}

	//{left, right}
	if (n <= 0)
		moves.push_back(Action::move::right);
	else if (n >= state.Get_grid_size() - 1)
		moves.push_back(Action::move::left);
	else
	{
		moves.push_back(Action::move::right);
		moves.push_back(Action::move::left);
	}

	return moves;
}

State Problem::Result(State state, Action::move action)
{
	//TODO: Given a state and an action, return the state of the world after the action has been applied to it
	//FIND THE EMPTY TILE
	int m, n;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			if (state.Get_tiles()[i][j] == -1)
			{
				m = i;
				n = j;
			}
		}
	}
	

	//PERFORM SPECIFIED MOVE, SHIFT ALL TILES ACCORDINGLY
	int tile, tile_m, tile_n;

	if (action == Action::move::up)
	{
		tile_m = m + 1;
		tile_n = n;
	}
		

	if (action == Action::move::down)
	{
		tile_m = m - 1;
		tile_n = n;
	}

	if (action == Action::move::left)
	{
		tile_m = m;
		tile_n = n + 1;
	}
	
	if (action == Action::move::right)
	{
		tile_m = m;
		tile_n = n - 1;
	}

	tile = state.Get_tiles()[tile_m][tile_n];

	//SET TILES
	state.Set_tile(m, n, tile);
	state.Set_tile(tile_m, tile_n, -1);

	return state;
}

bool Problem::Goal_test(State state)
{
	//TODO: check if goal has been reached

	//DEFINE GOAL STATE
	std::vector<int> goal_state_temp;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			goal_state_temp.push_back(state.Get_tiles()[i][j]);
		}
	}

	std::sort(goal_state_temp.begin(), goal_state_temp.end());

	std::vector<int> goal_state;
	for (size_t i = 0; i < goal_state_temp.size(); i++)
	{
		if (i == goal_state_temp.size() - 1)
			goal_state.push_back(-1);
		else
			goal_state.push_back(goal_state_temp[i + 1]);
	}
	

	//ITERATE OVER STATE AND COMPAIR WITH GOAL STATE

	return false;
}
