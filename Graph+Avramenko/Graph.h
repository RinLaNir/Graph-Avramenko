#pragma once

#include <vector>
#include <list>

using namespace std;

struct Edge {
	int src;
	int dest;
};

class Graph
{
public:
	vector<vector<int>> adjList;

	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);

		for (auto &edge : edges)
		{
			adjList[edge.src].push_back(edge.dest);

		}
	}
};

//FUNCTIONS
extern void addedge(list<int> *ls, int x, int y);
extern void all_addedge(vector<Edge> const& edges, list<int> *ls, int n);
extern void inputedges(vector<Edge> & edges, int n);
extern void DFS(list<int>*ls, int num, int x);
extern void printGraph(Graph const& graph, int m);