#include <queue>
#include <iostream>

#include "Action.h"
#include "Node.h"
#include "Problem.h"
#include "State.h"

int main(int argc, char *argv[])
{
	int line;
	int count = -1;
	int grid_size;

	std::vector<std::vector<int>> tiles;
	std::vector<int> row;

	while (std::cin >> line && !std::cin.eof())
	{
		if (count == -1)
			grid_size = line;
		else
		{
			if (count > 0 && count % grid_size == 0)
			{
				tiles.push_back(row);
				row.clear();
			}
			row.push_back(line);
		}

		count++;
	}
	tiles.push_back(row);


	State initial_state(grid_size, tiles);
	Problem p(initial_state);

	//Node n(initial_state, nullptr, Action::move::empty);

	Node* n = new Node(initial_state, nullptr, Action::move::empty);
	std::queue<Node*> q;

	q.push(n);
	
	//int iteration = 0;
	//FIND SOLUTION
	while (q.size() > 0)
	{
		//std::cout << iteration << std::endl;

		n = q.front();
		q.pop();

		if (p.Goal_test(n->Get_state()))
		{
			break;
		}

		std::vector<Action::move> actions = p.Actions(n->Get_state());

		for (size_t i = 0; i < actions.size(); i++)
		{
			State s = p.Result(n->Get_state(), actions[i]);
			//Node child(s, &n, actions[i]);
			Node* child = new Node(s, n, actions[i]);
			q.push(child);
			//q.push(&child);
		}

		//iteration++;
	}

	//RECONSTRUCT PATH
	std::vector<Action::move> path;

	while (n->Get_action() != Action::move::empty)
	{
		path.push_back(n->Get_action());
		n = &n->Get_parent();
	}

	//ITERATE IN REVERSE AND DISPLAY
	for (int i = path.size() -1; i > -1; i--)
	{
		if (i == path.size() - 1)
			std::cout << moves[path[i]];
		else
			std::cout << ',' << moves[path[i]];
	}

	return 0;
}