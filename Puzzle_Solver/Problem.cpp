#include "Problem.h"



Problem::Problem()
{
}

Problem::Problem(State state):
	m_state(state)
{
}


Problem::~Problem()
{
}

bool Problem::Goal_test(State state)
{
	return false;
}
