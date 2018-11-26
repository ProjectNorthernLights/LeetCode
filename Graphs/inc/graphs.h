/*
 * list.h
 *
 *  Created on: Nov 25, 2018
 *      Author: pradosh
 */

#ifndef GRAPHS_H_
#define GRAPHS_H_

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graphs{
private:
  int V;
  list<int> *Adj;

public:
  //constructor
  Graphs(int V){
    cout << "Initializing graph with vertices : " << V << endl;
    this->V = V;
    Adj = new list<int> [V];
  }

  void BFS(int source);
  void DFS(int source, vector<bool> &visited);
  void DFSHelper(int source);
  void addedge(int from, int to);
};



#endif /* GRAPHS_H_ */
