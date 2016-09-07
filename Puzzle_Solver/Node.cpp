#include "Node.h"



Node::Node()
{
}

Node::Node(State state, Node* parent, Action action):
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

Action Node::Get_action()
{
	return m_action;
}
