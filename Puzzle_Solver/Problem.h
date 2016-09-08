#pragma once
#include "Action.h"
#include "State.h"
#include <vector>
#include <algorithm> 

class Problem
{
public:
	Problem(State state);
	~Problem();

	std::vector<Action::move> Actions(State state);
	State Result(State state, Action::move action);
	bool Goal_test(State state);

private:
	State m_state;
};

