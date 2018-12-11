//============================================================================
// Name        : disjoint.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSet{
public:

	class Node{
	public:
		int data;
		int rank;
		Node *parent;
	};

	void makeset(int x);
	void makeunion(int x, int y);

	Node* DisjointSet::find(int x){
		Node *parent = nullptr;

		unordered_map<int , Node*> ::iterator itr;
		itr = hashmap.find(x);

		if(itr != hashmap.end()){
			parent = itr->second;
		}

		if(parent->data == x){
			return parent;
		}
		else{
	        parent = find(parent->data);
	        hashmap.emplace(x, parent);
	        return parent;
		}
	}

	//constructor
	DisjointSet(int max){
	  for (int i = 0 ; i < max; i ++){
		  makeset(i);
	  }
	}

	//map to store the data,pointer pairs
	unordered_map<int , Node*> hashmap;

};

void DisjointSet::makeset(int x){
	Node *new_node = new Node();
	new_node->data = x;
	new_node->parent = new_node;
	new_node->rank = 0;
    hashmap.emplace(x, new_node);
    cout << "created node " << new_node << " with data " << new_node->data << endl;
}

void DisjointSet::makeunion(int x, int y){
	//find the parent of x and y
	Node *parent1 = find(x);
	Node *parent2 = find(y);

	//if parent are same, then they belong to same set
	if(parent1 == parent2){
		return;
	}

	//if different, use rank to unify them
	if(parent1->rank >= parent2->rank){
		parent1->rank ++;
		parent2->parent = parent1;
	}else{
		parent2->rank ++;
		parent1->parent = parent2;
	}
}

int main() {
	//make set
	DisjointSet ud(10);

	//union
	ud.makeunion(1,2);
	ud.makeunion(3,4);
	return 0;
}
