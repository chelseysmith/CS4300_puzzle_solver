#pragma once

#include "Action.h"
#include "State.h"

class Node
{
public:
	//Node(Node& node);
	Node(State state, Node* parent, Action::move action);
	~Node();

	State Get_state();
	Node Get_parent();
	Action::move Get_action();

private:
	State m_state;
	Node* m_parent;
	Action::move m_action;
};

