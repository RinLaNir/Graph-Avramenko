#ifndef GraphH
#define GraphH
#include <iostream> 
#include <limits.h> 
#include <list> 
#include <stack> 
#include <vector>
#define NINF INT_MIN 
using namespace std;

// Graph is represented using adjacency list. Every  
// node of adjacency list contains vertex number of  
// the vertex to which edge connects. It also  
// contains weight of the edge  
class AdjListNode {
	int v;
	int weight;

public:
	AdjListNode(int _v, int _w)
	{
		v = _v;
		weight = _w;
	}
	int getV() { return v; }
	int getWeight() { return weight; }
};

// Class to represent a graph using adjacency list  
// representation  
class Graph {
	int V; // No. of vertices'  

		   // Pointer to an array containing adjacency lists  
	list<AdjListNode>* adj;

	// A function used by longestPath  
	void DFSUtil(int v, bool visited[]);
	void DFS(int src, int prev_len, int* max_len, vector<bool> &visit);
	int longestCable(int n);

public:
	Graph(int V); // Constructor  
	~Graph(); // Destructor 

			  // function to add an edge to graph  
	void addEdge(int u, int v, int weight);
	void connectedComponents();
	// Finds longest distances from given source vertex  
	void longestPath(int s);
};

#endif