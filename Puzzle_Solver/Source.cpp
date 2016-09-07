#include <queue>
#include <iostream>

#include "Action.h"
#include "Node.h"
#include "Problem.h"
#include "State.h"

int main(int argc, char *argv[])
{
	std::cout << "Have " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

	State initial_state;
	Problem p(initial_state);

	Node inital_node(initial_state, nullptr, Action::move::empty);
	std::queue<Node> q;

	q.push(inital_node);
	
	//FIND SOLUTION
	while (q.size() > 0)
	{
		Node n(q.pop());

		if (p.Goal_test(n.Get_state()))
			break;

		std::vector<Action::move> actions = p.Actions(n.Get_state());

		for (size_t i = 0; i < actions.size(); i++)
		{
			State s = p.Result(n.Get_state(), actions[i]);
			Node child(n.Get_state(), &n, actions[i]);
			q.push(child);
		}
	}

	//RECONSTRUCT PATH
	std::vector<Action::move> path;

	while (true)
	{
		break;
	}
	
}