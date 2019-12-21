#include "Graph.h"
#include <iostream>

using namespace std;

void test_1() {
	Graph g(6);
	g.addEdge(1, 0, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 3);
	g.addEdge(3, 5, 2);

	cout << "Following are connected components \n";
	g.connectedComponents();
	cout << " \n";
	int s = 2;
	cout << "Max vertex for " << s << " " << g.MaxVertex(s);
	cout << " \n";
	g.MaxShortestDistance(s);
}

int main()
{
	test_1();

	return 0;
}