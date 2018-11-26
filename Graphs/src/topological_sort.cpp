void Graphs::topologicalSortHelper(int node, vector<bool> &v, stack<int> &s){
  v[node] = true;
  for(list<int> :: iterator itr = Adj[node].begin();
      itr != Adj[node].end();
      ++itr)
  {
    if(v[*itr] == false)
      topologicalSortHelper(*itr, v, s);
  }

  //once you run out of neigboring node, push that vertex into stack
  cout << "Pushing " << node << "into stack" << endl;
  s.push(node);
  return;
}


void Graphs::topologicalSort(void){

  vector<bool> visited(V, false);
  stack<int> mystack;

  //perform topo sort on all vertices one by one
  for(int i = 0; i < V; i ++){
    if( visited[i] == false)
      this->topologicalSortHelper(i, visited, mystack);
  }

  //Print the stack
  while(!mystack.empty()){
    cout << mystack.top() << endl;
    mystack.pop();
  }
}

void Graphs::addDirectedEdge(int u, int v){
  cout << "Adding edge from " << u << " to " << v <<endl;
  Adj[u].push_back(v);
}

int main() {

  //Instantiate a graph with 4 nodes
  Graphs g(7);

  g.addDirectedEdge(0,1);
  g.addDirectedEdge(1,2);
  g.addDirectedEdge(2,3);
  g.addDirectedEdge(2,4);
  g.addDirectedEdge(4,5);
  g.addDirectedEdge(4,6);

  //Run topo sort
  g.topologicalSort();
	return 0;
}
