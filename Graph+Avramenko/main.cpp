#include <iostream> 
#include <vector>
#include <stack>
#include "Graph.h"

int main()
{
	int n;
	int m = 7;
	cout << "Input number of edges\n";
	cin >> n;
	cout << "Input number of vertices\n";
	cin >> m;

	vector<Edge> edges =
	{
	 { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
	 { 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	Graph graph(edges, m);

	printGraph(graph, m);

	return 0;
}