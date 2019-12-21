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
			int max_vertex = INT_MIN;
			vector< bool > visit(V, false);
			DFS(v, 0, &max_len, &max_vertex, visit);
			cout << "Diametr " << max_len << "\n";
		}
	}
	cout << "Number of components " << k << " ";
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
	int max_vertex = INT_MIN;

	// call DFS for each city to find maximum
	// length of cable
	for (int i = 1; i <= n; i++)
	{
		// initialize visited array with 0
		vector< bool > visited(n + 1, false);

		// Call DFS for src vertex i
		DFS(i, 0, &max_len, &max_vertex, visited);
	}

	return max_len;
}

void Graph::DFS(int src,int prev_len, int* max_len, int* max_vertex, vector <bool> &visited)
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
			DFS(node.getV(), curr_len, max_len, max_vertex, visited);
		}		

		// If total cable length till now greater than
		// previous length then update it
		if ((*max_len) < curr_len) {
			*max_len = curr_len;
			*max_vertex = node.getV();
		}

		// make curr_len = 0 for next adjacent
		curr_len = 0;
	}
}

// search for the farthest point
int Graph::MaxVertex(int src) {
	int max_len = INT_MIN;
	int max_vertex = INT_MIN;

	vector< bool > visited(V, false);
	DFS(src, 0, &max_len, &max_vertex, visited);

	return max_vertex;
}

bool  Graph::BFS(int src, int dest, int pred[], int dist[])
{
	// a queue to maintain queue of vertices whose 
	// adjacency list is to be scanned as per normal 
	// DFS algorithm 
	list<int> queue;

	// boolean array visited[] which stores the 
	// information whether ith vertex is reached 
	// at least once in the Breadth first search 
	vector< bool > visited(V, false);

	// initially all vertices are unvisited 
	// so v[i] for all i is false 
	// and as no path is yet constructed 
	// dist[i] for all i set to infinity 
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	// now source is first to be visited and 
	// distance from source to itself should be 0 
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	// standard BFS algorithm 
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		list<AdjListNode>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			AdjListNode node = *i;
			if (visited[node.getV()] == false) {
				visited[node.getV()] = true;
				dist[node.getV()] = dist[u] + node.getWeight();
				pred[node.getV()] = u;
				queue.push_back(node.getV());

				// We stop BFS when we find 
				// destination. 
				if (node.getV() == dest)
					return true;
			}
		}
	}

	return false;
}

// utility function to print the shortest distance  
// between source vertex and destination vertex 
int Graph::ShortestDistance(int s, int dest)
{
	// predecessor[i] array stores predecessor of 
	// i and distance array stores distance of i 
	// from s 
	int pred[1024], dist[1024];

	if (BFS(s, dest, pred, dist) == false)
	{
		return 0;
	}

	return dist[dest];
}

void Graph::MaxShortestDistance(int src) {
	int max = 0, last = 0, point;
	for (int i = 0; i < V; ++i) {
		last = ShortestDistance(src, i);
		if (max < last) {
			max = last;
			point = i;
		}
	}
	cout << "Farthest point of " << src << " is " << point << endl;
}