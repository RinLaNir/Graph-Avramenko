#include <iostream> 
#include <limits.h> 
#include <list> 
#include <stack> 
#include <vector> 
#include "Graph.h"
#define NINF INT_MIN 

#define NINF INT_MIN

using namespace std;

Graph::Graph(int V) // Constructor  
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

Graph::~Graph() // Destructor  
{
	delete[] adj;
}


void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node); // Add v to u's list  
	AdjListNode node2(u, weight);
	adj[v].push_back(node2);
}

// Method to print connected components in an 
// undirected graph 
void Graph::connectedComponents()
{
	// Mark all the vertices as not visited 
	int k = 0;
	bool *visited = new bool[V];
	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v<V; v++)
	{
		if (visited[v] == false)
		{
			// print all reachable vertices 
			// from v 
			DFSUtil(v, visited);
			k++;
			int max_len = INT_MIN;
			vector< bool > visit(V, false);
			DFS(v, 0, &max_len, visit);
			cout << "Diametr " << max_len << "\n";
		}
	}
	cout << "Number if components " << k << " ";
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it 
	visited[v] = true;

	// Recur for all the vertices 
	// adjacent to this vertex 
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		if (!visited[(*i).getV()]) DFSUtil((*i).getV(), visited);
	}
}


// n is number of cities or nodes in graph
// cable_lines is total cable_lines among the cities
// or edges in graph
int Graph::longestCable(int n)
{
	// maximum length of cable among the connected
	// cities
	int max_len = INT_MIN;

	// call DFS for each city to find maximum
	// length of cable
	for (int i = 1; i <= n; i++)
	{
	// initialize visited array with 0
		vector< bool > visited(n + 1, false);

	// Call DFS for src vertex i
	DFS(i, 0, &max_len, visited);
	}

	return max_len;
}

void Graph::DFS(int src,int prev_len, int* max_len, vector <bool> &visited)
{
	// Mark the src node visited
	visited[src] = 1;

	// curr_len is for length of cable from src
	// city to its adjacent city
	int curr_len = 0;

	// Adjacent is pair type which stores
	// destination city and cable length
	pair < int, int > adjacent;

	// Traverse all adjacent
	list<AdjListNode>::iterator i;
	for (i = adj[src].begin(); i != adj[src].end(); ++i)
	{
		// If node or city is not visited
		AdjListNode node = *i;
		if (!visited[node.getV()])
		{
			// Total length of cable from src city
			// to its adjacent
			curr_len = prev_len + node.getWeight();

			// Call DFS for adjacent city
			DFS(node.getV(), curr_len, max_len, visited);
		}		

		// If total cable length till now greater than
		// previous length then update it
		if ((*max_len) < curr_len)
			*max_len = curr_len;

		// make curr_len = 0 for next adjacent
		curr_len = 0;
	}
}
