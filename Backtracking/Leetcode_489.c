/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
  
  //use a map to capture the coordinates that have already
  //been visited. Since we dont know the grid size beforehand, we cant use a 
  //array and managing a vector is little complicated
  
  unordered_map<int, unordered_map<int, bool>> visited;
  
  //possible row and column combinations the robot can move
  int x_coordinate[4] = {-1, 0,  1, 0};
  int y_coordinate[4] = {0 , -1, 0,  1};

  //this direction can be a global. See the trick
  int cur_direction = 0; // 4 directions 
  
  
  void cleanRoomHelper(int row, int col, int cur_direction, Robot &robot)
  {
    if ( visited[row][col] == true)
    {
      //base case
      return;
    }
    else
    {
      //mark the cell visited
      visited[row][col] = true;         
      robot.clean();
      
      for (int i = 0; i < 4; i++)
      {
        //choose
        int new_row = row + x_coordinate[cur_direction];
        int new_column = col + y_coordinate[cur_direction];
                
        if(robot.move())
        {
          //explore 
          cleanRoomHelper(new_row, new_column, cur_direction, robot);
          
          //backtrack
          robot.turnRight();
          robot.turnRight();
          
          robot.move();
          
          robot.turnRight();
          robot.turnRight();
          
          new_row = new_row - x_coordinate[cur_direction];
          new_column = new_column - y_coordinate[cur_direction];
          
        }
        
        robot.turnLeft();
        cur_direction = (cur_direction + 1)%4;
      }
    }
  }
  
    
  void cleanRoom(Robot& robot)
  {
    cleanRoomHelper(0, 0, cur_direction, robot);
  }
};
