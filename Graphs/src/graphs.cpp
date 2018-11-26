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
 */

#include "graphs.h"

void Graphs::DFSHelper(int source){
  cout << "Running DFS with source " << source << endl;

  //initialize a bool array to false
  vector<bool> visited(V, false);
  this->DFS(source, visited);
}

void Graphs::DFS(int s, vector<bool> &visited){
  visited[s] = true;
  for(list<int> :: iterator itr = Adj[s].begin();
      itr != Adj[s].end();
      ++itr)
  {
    if(visited[*itr] == false){
      cout << "Visiting node " << *itr << endl;
      DFS(*itr, visited);
    }
  }
  return;
}

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

  //Run DFS with diff nodes
  g.DFSHelper(0);
  g.DFSHelper(1);
	return 0;
}
