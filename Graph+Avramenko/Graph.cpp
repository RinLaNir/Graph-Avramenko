#include <iostream> 
#include <vector>
#include <list>
#include <stack>
#include "Graph.h"
using namespace std;

void addedge(list<int> *ls, int x, int y) {
	ls[x].push_back(y);
	ls[y].push_back(x);
	return;
}

void all_addedge(vector<Edge> const& edges, list<int> *ls, int n) {
	for (int i = 0; i<n; i++) {
		int x = edges[i].src;
		int y = edges[i].dest;
		ls[x].push_back(y);
		ls[y].push_back(x);
		return;
	}
}

void inputedges(vector<Edge> & edges, int n) {

	cout << "Input edges:  \n";
	for (int i = 0; i<n; i++) {
		edges.push_back(Edge());
		cin >> edges[i].src;
		cin >> edges[i].dest;
	}
	cout << "You entered:  \n";
	for (int i = 0; i<n; i++) {
		cout << "----\n";
		cout << " " << edges[i].src << " ";
		cout << edges[i].dest << "\n";
	}
}

void DFS(list<int>*ls, int num, int x) {
	bool *visit = new bool[num];
	for (int i = 0;i<num;i++) {
		visit[i] = false;
	}
	stack<int> st;
	st.push(x);
	while (!st.empty()) {
		int s = st.top();
		st.pop();
		if (!visit[s]) {
			cout << s << " ";
			visit[s] = true;
			list<int>::iterator it;
			for (it = ls[s].begin();it != ls[s].end();it++) {
				st.push(*it);
			}
		}
	}
}

void printGraph(Graph const& graph, int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << i << " ---";

		for (int v : graph.adjList[i])
			cout << "--> " << v << " ";
		cout << endl;
	}
}