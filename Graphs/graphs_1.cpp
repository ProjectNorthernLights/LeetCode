//============================================================================
// Name        : list.cpp
// Author      : pnanda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

void printme(list<pair<int, int>> adjlist[], int V)
{
  cout << "Adjacency List contents are "<< endl;
  list<pair<int, int>> :: iterator itr;

  for(int i = 0; i < V; i++){
    cout << "Vertex " << i << " Adjlist are " <<endl;
    for( itr = adjlist[i].begin(); itr != adjlist[i].end(); ++itr ){
      cout << "[" << itr->first << "," << itr->second << "]" << endl;
    }
  }
}

int main() {
  int vertices = 4;
  list<pair<int,float>> AdjList[vertices];

  //for node 0 edge to node 1 , weight is 2.5
  AdjList[0].push_back(make_pair(1,2.5));
  AdjList[0].push_back(make_pair(2,3.0));

  AdjList[1].push_back(make_pair(3,4));
  AdjList[1].push_back(make_pair(4,4));

  AdjList[2].push_back(make_pair(3,5));
  AdjList[3].push_back(make_pair(1,8));

  printme(AdjList, vertices);
	return 0;
}
