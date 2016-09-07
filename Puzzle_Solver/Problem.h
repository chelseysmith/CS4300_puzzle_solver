#pragma once
#include "Action.h"
#include "State.h"
#include <vector>

class Problem
{
public:
	Problem();
	Problem(State state);
	~Problem();

	std::vector<State> Actions(State state);
	State Result(State state, Action action);
	bool Goal_test(State state);

private:
	State m_state;
};

