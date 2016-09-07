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

	//FIND THE EMPTY TILE

	//CHECK THE LEFT, UP, RIGHT DOWN FROM SAID TILE, IF THEY ARE LEGAL "NOT OUT OF BOUNDS", ADD TO RETURN VECTOR

	return std::vector<Action::move>();
}

State Problem::Result(State state, Action::move action)
{
	//TODO: Given a state and an action, return the state of the world after the action has been applied to it

	//PERFORM SPECIFIED MOVE, SHIFT ALL TILES ACCORDINGLY
	return State();
}

bool Problem::Goal_test(State state)
{
	//TODO: check if goal has been reached

	//DEFINE GOAL STATE

	//ITERATE OVER STATE AND COMPAIR WITH GOAL STATE

	return false;
}
