#pragma once

#include "Action.h"
#include "State.h"

class Node
{
public:
	Node();
	Node(State state, Node* parent, Action action);
	~Node();

	State Get_state();
	Node Get_parent();
	Action Get_action();

private:
	State m_state;
	Node* m_parent;
	Action m_action;
};

