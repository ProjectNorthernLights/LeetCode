class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
  
      
      // Idea is to check if the graph is 2 colorable
      //Have an array of colors
      vector<int> colorArray(graph.size() , -1);
      
      //-1 means no color is assigned as of now
      //1 denotes RED
      //0 denotes BLUE
      queue<int> q ;
      q.push(0);
      colorArray[0] = 1;
      
      //Do a BFS and color the nodes
      while(!q.empty())
      {
        int current_node = q.front();
        
        //push neigbors of current node into queue
        for(int neighbors = 0; neighbors < graph[current_node].size(); neighbors++)
        {
          //if not already colored, then push it and assign alternate color
          if( colorArray[graph[current_node][neighbors]] == -1)
          {
            q.push(graph[current_node][neighbors]);
            colorArray[graph[current_node][neighbors]] = 1 - colorArray[current_node];
          }
          else if( colorArray[graph[current_node][neighbors]] == colorArray[current_node])
          {
            return false;
          } 
        }
                              
      //pop it out of queue
      q.pop();
    }
    return true;
  }
};
