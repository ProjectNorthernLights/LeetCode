//============================================================================
// Name        : BFS.cpp
// Author      : pnanda
// Version     :
// Copyright   : Your copyright notice
// Description : Create a Graph using adjacency list and perform BFS
//                 Traversal on it
//============================================================================
/*Graph represented as below
 *
 *           0
 *     1           2
 *  3    4     5      6
 *
 *
 *Output:
Initializing 7 number of edges
Adding edge between 0 and 1
Adding edge between 0 and 2
Adding edge between 1 and 3
Adding edge between 1 and 4
Adding edge between 2 and 5
Adding edge between 2 and 6
Running BFS with source 0
0
1
2
3
4
5
6
Running BFS with source 1
1
0
3
4
2
5
6
 */

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graphs{
public:
  int V;
  list<int> *Adj;

  //constructor
  Graphs(int V){
    cout << "Initializing " << V << " number of edges" <<endl;
    this->V = V;
    Adj = new list<int> [V];
  }

  void BFS(int source);
  void addedge(int from, int to);
};

void Graphs::BFS(int s){

  cout << "Running BFS with source " << s << endl;

  //need a bool to make sure we dont end up revisiting same nodes
  vector<bool> visited(V, false);

  //push the nodes into a Q
  queue<int> Q;

  Q.push(s);

  while(!Q.empty()){

    int front_elem =  Q.front();
    visited[front_elem] = true;

    cout << front_elem << endl;

    //push the nodes in the adjacency list of a particular node
    for(list<int> :: iterator itr = Adj[front_elem].begin();
        itr != Adj[front_elem].end();
        itr++)
    {
      //if the node has not been visited then only queue it up
      if(visited[*itr] == false)
        Q.push(*itr);
    }

    //pop the element
    Q.pop();
  }
}

//This is an undirected graph
void Graphs::addedge(int u, int v){
  cout << "Adding edge between " << u << " and " << v <<endl;
  Adj[u].push_back(v);
  Adj[v].push_back(u);
}

int main() {

  //Instantiate a graph with 4 nodes
  Graphs g(7);

  //create edges
  g.addedge(0,1);
  g.addedge(0,2);

  g.addedge(1,3);
  g.addedge(1,4);

  g.addedge(2,5);
  g.addedge(2,6);

  //Run BFS with diff nodes
  g.BFS(0);
  g.BFS(1);
	return 0;
}
