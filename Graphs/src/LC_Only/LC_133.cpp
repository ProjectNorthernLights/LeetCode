/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/*
Idea is to do a BFS over the orginal graph and make a
level by level copy of the nodes and link them.
*/

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      
      //sanitize
      if(node == nullptr)
        return nullptr;
      
      UndirectedGraphNode *newSrc = new UndirectedGraphNode(node->label);
     // newSrc->label = node->label;

      //maintain a hashmap of <key= orginal_node, value = cloned_node>,
      //<src_node , cloned_node> so as to keep track of what nodes
      //have already been cloned
      unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
      
      //put the cloned node
      map[node] = newSrc;
      
      //maintain a q for regular BFS traversal
      queue<UndirectedGraphNode *> q;
      q.push(node);
      
      while(!q.empty())
      {
        UndirectedGraphNode *frontNode = q.front();
        
        //iterate over its adj list
        int numOfNeighbor = frontNode->neighbors.size();
        for(int i = 0; i < numOfNeighbor; i++)
        {
          //if a src node is not already cloned.
          //create it
          if(map.find(frontNode->neighbors[i]) == map.end())
          {
            UndirectedGraphNode *newClonedNode = new UndirectedGraphNode(frontNode->neighbors[i]->label);
            
            //put this mapping in the map
            map[frontNode->neighbors[i]] = newClonedNode;
            
            //push it into the q
            q.push(frontNode->neighbors[i]);
          }
          
         //if the cloned node is already created, just copy over the 
          //adjacency list only
          UndirectedGraphNode *clonedNode = map[frontNode];
          clonedNode->neighbors.push_back(map[frontNode->neighbors[i]]);
        }      
        
        q.pop();
      }//q.empty()
      
      return map[node];
    }
};
