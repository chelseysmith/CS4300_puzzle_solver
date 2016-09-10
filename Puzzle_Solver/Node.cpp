#include "Node.h"

Node::Node(State state, Node* parent, Action::move action):
	m_state(state),
	m_parent(parent),
	m_action(action)
{
}

Node::~Node()
{
}

State Node::Get_state()
{
	return m_state;
}

Node Node::Get_parent()
{
	return *m_parent;
}

Action::move Node::Get_action()
{
	return m_action;
}
