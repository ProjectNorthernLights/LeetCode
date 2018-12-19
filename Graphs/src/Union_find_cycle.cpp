class Solution {
public:
  // Lets try doing this with a Disjoint Data Set Data Structure
    class DisjointSet{
    public:
      //represented as <vertex <rank, parent>>
      unordered_map<int, pair<int, int>> disjointset;
      int rank;
      
      DisjointSet(set<int> DistinctNodes){
        rank = 0;
        makeSet(DistinctNodes);  
      }
      
      //perform findset and path compression
      int findSet(int u)
      {
        auto itr = disjointset.find(u);
        if(itr != disjointset.end()){
          if(itr->second.second == u)
            return u;
          else{
            int interim_parent = findSet(itr->second.second);
            disjointset[itr->first] = make_pair(itr->second.first, interim_parent);
            return interim_parent;
          }
        }
        return -1;
      }
      
      //unify by rank
      void unionSet(int u, int v)
      {
        int set_x = findSet(u);
        int set_y = findSet(v);
        
        //if dont belong to same set, then unify
        if(set_x != set_y)
        {
          auto it_set_x = disjointset.find(set_x);
          auto it_set_y = disjointset.find(set_y);
          
          int rank_u = it_set_x->second.first;
          int rank_v = it_set_y->second.first;
          
          if(rank_u == rank_v){
            rank_u ++;
            disjointset[set_x] = make_pair(rank_u, it_set_x->second.second);
          }
            
          
          if(rank_u >= rank_v){
            disjointset[set_y] = make_pair(rank_v, set_x);
          }else{
            disjointset[set_x] = make_pair(rank_u, set_y);
          }
        }
        else
          return;
      }
      
      void makeSet(set<int> setOfNodes){
        for(auto itr = setOfNodes.begin(); itr != setOfNodes.end() ; itr++){
          disjointset.emplace(*itr, make_pair(rank, *itr));
        }  
      }
    };
  
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      //iterate over the pair and add elemnets to a set so that any duplicates are erased
      set<int> nodes;
      for(auto itr = prerequisites.begin(); itr != prerequisites.end(); itr++){
        nodes.insert(itr->first);
        nodes.insert(itr->second);
      }
      
      //create the DDS
      DisjointSet ds(nodes);
      
      //Now iterate over the nodes and check if cycle exists or not
      for(auto itr = prerequisites.begin(); itr != prerequisites.end(); itr++)
      {
        int u = itr->first;
        int v = itr->second;
        
        int set_x = ds.findSet(u);
        int set_y = ds.findSet(v);
        
        //cycle exists
        if(set_x == set_y)
        {
          return false;
        }
        else{
          ds.unionSet(u, v);
        }
      }
      
      return true;
    }
};
