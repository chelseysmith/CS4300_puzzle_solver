#include "Node.h"


//Node::Node(Node & node):
//	m_parent(&node)
//{
//	//m_action = node->Get_action();
//	//m_parent = &node->Get_parent();
//	//m_state = node->Get_state();
//}

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
