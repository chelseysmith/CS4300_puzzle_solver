#include "Problem.h"


Problem::Problem(State state)
{
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

	for (size_t i = 0; i < goal_state_temp.size(); i++)
	{
		if (i == goal_state_temp.size() - 1)
			m_goal_state.push_back(-1);
		else
			m_goal_state.push_back(goal_state_temp[i + 1]);
	}

}


Problem::~Problem()
{
}

std::vector<Action::move> Problem::Actions(State state)
{
	//TODO: Given a state, return a vector of all legal actions
	std::vector<Action::move> moves;

	//FIND THE EMPTY TILE
	int n, m;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			if (state.Get_tiles()[i][j] == -1)
			{
				n = i;
				m = j;
			}
		}
	}

	//CHECK THE LEFT, UP, RIGHT DOWN FROM SAID TILE, IF THEY ARE LEGAL "NOT OUT OF BOUNDS", ADD TO RETURN VECTOR
	//{up, down}
	if (n <= 0)
		moves.push_back(Action::move::up);
	else if(n >= state.Get_grid_size() - 1)
		moves.push_back(Action::move::down);
	else
	{
		moves.push_back(Action::move::up);
		moves.push_back(Action::move::down);
	}

	//{left, right}
	if (m <= 0)
		moves.push_back(Action::move::left);
	else if (m >= state.Get_grid_size() - 1)
		moves.push_back(Action::move::right);
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
	int n, m;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			if (state.Get_tiles()[i][j] == -1)
			{
				n = i;
				m = j;
			}
		}
	}
	

	//PERFORM SPECIFIED MOVE, SHIFT ALL TILES ACCORDINGLY
	int tile, tile_n, tile_m;

	if (action == Action::move::up)
	{
		tile_n = n + 1;
		tile_m = m;
	}
		

	if (action == Action::move::down)
	{
		tile_n = n - 1;
		tile_m = m;
	}

	if (action == Action::move::left)
	{
		tile_n = n;
		tile_m = m + 1;
	}
	
	if (action == Action::move::right)
	{
		tile_n = n;
		tile_m = m - 1;
	}

	tile = state.Get_tiles()[tile_n][tile_m];

	//SET TILES
	state.Set_tile(n, m, tile);
	state.Set_tile(tile_n, tile_m, -1);

	return state;
}

bool Problem::Goal_test(State state)
{
	//TODO: check if goal has been reached

	//DEFINE GOAL STATE
	std::vector<int> current_state;
	for (size_t i = 0; i < state.Get_grid_size(); i++)
	{
		for (size_t j = 0; j < state.Get_grid_size(); j++)
		{
			current_state.push_back(state.Get_tiles()[i][j]);
		}
	}
	

	//ITERATE OVER CURRENT STATE AND COMPAIR WITH GOAL STATE
	for (size_t i = 0; i < current_state.size(); i++)
	{
		for (size_t j = 0; j < m_goal_state.size(); j++)
		{
			if (i == j)
			{
				if (current_state[i] != m_goal_state[j])
					return false;
			}
		}
	}

	return true;
}
