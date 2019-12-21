#include "Graph.h"
#include <iostream>

using namespace std;

void test_1() {
	Graph g(5);
	g.addEdge(1, 0, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);

	cout << "Following are connected components \n";
	g.connectedComponents();
	cout << " \n";
}

int main()
{
	test_1();

	return 0;
}