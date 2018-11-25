/*
Update : FOllow this youtube tutorial which solves this problem
with a bit of combinatorics knowledge.

https://www.youtube.com/watch?v=OkJKxoDbQ_c 

*/

class Solution {
public:
    
    int countHelper(int n, vector<bool> &visited , int begin)
    {
      if(begin == n)
      {
        return 1;
      }
      else
      {
        // initialize count to be 1, because the prefix number itself can be a valid target number.
        int cnt = 1; 
        
        for(int i = (begin == 0) ? 1 : 0; i < 10 ; i ++)
        {
          //explore only if its safe
          if(visited[i] == false)
          {
            //choose
            visited[i] = true;
            
            //explore
            cnt = cnt + countHelper(n, visited, begin + 1);
          
            //backtrack    
            visited[i] = false;
          }
        }
        
        return cnt ; 
      }
    }
  
    int countNumbersWithUniqueDigits(int n)
    {
      
      vector<bool> visited(10, false);
      int begin = 0;
        
      //with 10 unique digits, you can form only a 10 digit number
      //so anything above 10 has to be set to n = 10, because they cannot
      //return any unique numbers
      if(n > 10)
        n = 10;
      
      return countHelper(n, visited, begin);
    }
};
