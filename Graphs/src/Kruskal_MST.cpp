//============================================================================
// Name        : mst_disjoint_set.cpp
//
// Author      : 
// Version     : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph {
public:
	vector<pair<int, pair<int, int>>> edges;
	int V;
	int E;

	//constructor
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}

	//method to add an edge
	void addEdge(int src, int dest, int weight) {
		edges.push_back(make_pair(weight, make_pair(src, dest)));
	}

	//fnc to find Kruskals MST and return weight
	int K_MST(void);

	//utility function for spot checking the edge weight
	void edgeWeight(int src, int dest);
};

class DisjointSet {
public:

	unordered_map<int, pair<int, int>> disjoint_set;
	int rank;

	//create a hashset <node, <rank , parent>>
	DisjointSet(int V) {
		rank = 0;
		for (int i = 0; i < V; i++) {
			disjoint_set.emplace(i, make_pair(rank, i));
		}
	}

	//methods supported
	void union_set(int u, int v);
	int find_set(int v);
	int find_rank(int v);

	//utility to spot test the Disjoint Data Struc
	void test_disjoint_set(void);

};

void DisjointSet::test_disjoint_set(void) {
	unordered_map<int, pair<int, int>>::iterator itr;
	for (itr = disjoint_set.begin(); itr != disjoint_set.end(); itr++) {
		cout << "Node " << itr->first << " Parent " << itr->second.second
				<< " Rank " << itr->second.first << endl;
	}
}

int DisjointSet::find_rank(int u) {
	unordered_map<int, pair<int, int>>::iterator itr;
	itr = disjoint_set.find(u);
	if (itr != disjoint_set.end()) {
		return itr->second.first;
	} else
		return -1;
}

int DisjointSet::find_set(int u) {

	unordered_map<int, pair<int, int>>::iterator itr;
	itr = disjoint_set.find(u);

	if (itr != disjoint_set.end()) {
		if (itr->second.second == u)
			//if the parent is the element itself
			return u;
		else {
			//perform path compression
			int interim_parent = find_set(itr->second.second);
			disjoint_set[itr->first] = make_pair(itr->second.first,
					interim_parent);
			return interim_parent;
		}
	}
	cout << " Cannot find element in the hashset" << endl;
	return -1;
}

void DisjointSet::union_set(int u, int v) {

	int rank_1;
	int rank_2;

	int set_x = find_set(u);
	int set_y = find_set(v);

	//If same, that means they are in same set, return
	if (set_x == set_y)
		return;

	//else Unify by rank
	rank_1 = find_rank(set_x);
	rank_2 = find_rank(set_y);

	//this shouldnt happen
	if (rank_1 == -1 || rank_2 == -1)
		return;

	if (rank_1 >= rank_2) {
		disjoint_set[set_y] = make_pair(rank_2, set_x);
	} else if (rank_1 < rank_2) {
		disjoint_set[set_x] = make_pair(rank_1, set_y);
	}

	//Rank is only incremented for one of the sets
	//if both sets have same rank
	if (rank_1 == rank_2) {
		rank_1 = rank_1 + 1;
		disjoint_set[set_x] = make_pair(rank_1, set_x);
	}
	return;
}

void Graph::edgeWeight(int src, int dest) {
	vector<pair<int, pair<int, int>>>::iterator itr;

	for (itr = edges.begin(); itr != edges.end(); itr++) {
		if (itr->second.first == src && itr->second.second == dest) {
			cout << src << "<---->" << dest << " : " << itr->first << endl;
		}
	}
}

int Graph::K_MST(void) {

	DisjointSet ds(V);

	//sort by increasing edge
	sort(edges.begin(), edges.end());

	int total_weight = 0;

	//for each edge, keep adding to the MST
	vector<pair<int, pair<int, int>>>::iterator itr;
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		int u = itr->second.first;
		int v = itr->second.second;

		int set_x = ds.find_set(u);
		int set_y = ds.find_set(v);

		//Debug msgs
		//cout << u << "Parent is "<< ds.find_set(u) << endl;
		//cout << v << "Parent is "<< ds.find_set(v) << endl;
		//if belong to same set, then cycle is formed, so avoid cycle
		if (set_x != set_y) {
			cout << u << " - " << v << endl;
			total_weight = total_weight + itr->first;
			//merge the two nodes to one set
			ds.union_set(u, v);
		}
	}

	//ds.test_disjoint_set();
	return total_weight;
}

int main() {

	int V = 9;
	int E = 14;
	Graph g(V, E);

	//Make the graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	//check if graph is formed correctly
	//g.edgeWeight(4,5);

	//Make the DisjointSet to be able to find if the graph
	//has a cycle or not
	//DisjointSet ds(V);

	//Check if the DDS is formed correctly
	//ds.test_disjoint_set();
	//ds.union_set(1,2);
	//ds.union_set(5,6);
	//ds.union_set(1,5);
	//ds.union_set(6,7);
	//ds.union_set(4,5);
	//ds.union_set(5,6);
	//ds.test_disjoint_set();
	int wt = g.K_MST();
	cout << "MST weight " << wt << endl;
	return 0;
}
