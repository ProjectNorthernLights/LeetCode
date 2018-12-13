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

using namespace std;

class Graph{
public:
	vector<pair<int, pair<int, int>>> edges;
	int V;
	int E;

	//constructor
	Graph(int V, int E){
		this->V = V;
		this->E = E;
	}

	//method to add an edge
	void addEdge(int src, int dest, int weight){
      edges.push_back(make_pair(weight , make_pair(src, dest)));
	}

	//fnc to find Kruskals MST and return weight
	int K_MST();

	//utility function for spot checking the edge weight
	void edgeWeight(int src, int dest);
};

class DisjointSet{
public:

	unordered_map <int , pair<int, int>> disjoint_set;
    int rank ;

	//create a hashset <node, <rank , parent>>
	DisjointSet(int V){
	  rank = 0;
      for (int i = 0; i < V; i ++ )
      {
        disjoint_set.emplace(i, make_pair(rank, -1));
      }
    }

    //methods supported
	void union_set(int u, int v);
	int find_set(int v);
	int find_rank(int v);

	//utility to spot test the Disjoint Data Struc
	void test_disjoint_set(void);

};

void DisjointSet::test_disjoint_set(void){
   unordered_map <int , pair<int, int>> :: iterator itr;
   for(itr = disjoint_set.begin(); itr != disjoint_set.end(); itr++){
      cout << "Node " << itr->first << " Parent " << itr->second.second << " Rank " << itr->second.first << endl;
   }
}

int DisjointSet::find_rank(int u){
   unordered_map <int , pair<int, int>> :: iterator itr;
   itr = disjoint_set.find(u);
   if(itr != disjoint_set.end()){
	   return itr->second.first;
   }
   else
	   return -1;
}

int DisjointSet::find_set(int u){

   unordered_map <int , pair<int, int>> :: iterator itr;
   itr = disjoint_set.find(u);

   if(itr != disjoint_set.end()){
	   if(itr->second.second == -1)
		   return u;
	   else{
		   return find_set(itr->second.second);
	   }
   }
   return -1;
}

void DisjointSet::union_set(int u, int v){

   int rank_1 ;
   int rank_2 ;

   int parent_of_first_elem = find_set(u);
   int parent_of_second_elem = find_set(v);

   //If same, that means they are in same set, return
   if( parent_of_first_elem == parent_of_second_elem)
	   return;

   //else Unify by rank
   rank_1 = find_rank(u);
   rank_2 = find_rank(v);

   //this shouldnt happen
   if(rank_1 == -1 || rank_2 == -1)
	   return;

   if(rank_1 >= rank_2){
	   rank_1 = rank_1 + 1;
	   disjoint_set[u] = make_pair(rank_1, u);
	   disjoint_set[v] = make_pair(rank_2, u);
   }else{
	   rank_2++;
	   disjoint_set[v] = make_pair(rank_2, v);
	   disjoint_set[u] = make_pair(rank_1, v);
   }

   return;
}

void Graph::edgeWeight(int src, int dest){
	vector<pair<int, pair<int, int>>> :: iterator itr;

	for(itr = edges.begin(); itr != edges.end(); itr ++)
	{
	  if(itr->second.first == src &&
		   itr->second.second == dest)
	  {
		cout << src << "<---->" << dest << " : " << itr->first << endl;
	  }
	}
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
    DisjointSet ds(V);

    //Check if the DDS is formed correctly
    //ds.test_disjoint_set();
    ds.union_set(1,2);
    //ds.union_set(2,3);
    ds.test_disjoint_set();
	return 0;
}
