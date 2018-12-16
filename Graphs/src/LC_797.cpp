class Solution {
public:
  
    void helper(vector<vector<int>>& graph, int u, int v, vector<int> &pathFound, vector<vector<int>> &result, vector<bool> &visited)
    {
      
      //the DFS src node == dest , path exists
      if( u == v)
      {
        //path found
        pathFound.push_back(v);
        result.push_back(pathFound);
        pathFound.pop_back();
      }
      else
      {
        //choose
        visited[u] = true;
        pathFound.push_back(u);
        
        //explore
        for(int i = 0; i < graph[u].size(); i++)
        {
          int neighborNode = graph[u][i];
          if(!visited[neighborNode])
            helper(graph, neighborNode, v, pathFound, result, visited);
        }
        
        //unchoose
        visited[u] = false;
        pathFound.pop_back();
      }
      
      return ;
    }
  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<int> pathFound;
      vector<vector<int>> result;
      
      if(graph.empty())
        return result;
      
      int V = graph.size();
      
      int srcNode = 0;
      int destNode = V - 1;
      vector<bool> visited(V, false);
      
      //do a DFS walk
      helper(graph, srcNode, destNode, pathFound, result, visited);
      
      return result;
      
    }
};
