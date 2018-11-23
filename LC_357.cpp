//Below naive implementation shows TLE for n > 7. Need to come up with a better way

class Solution {
public:
  
  bool isUnique(int number, vector<bool> &visited )
  {
    //base condition
    if( number == 0)
      return true;
    else
    {
      //mark the most significant digit as visited
      int msd = number % 10;
    
      //i.e digit is already visited or "seen"
      if(visited[msd] == true)
        return false;
      else
        visited[msd] = true;
    
      number = number /10;
      
      return isUnique(number, visited);  
    }
  }
  
  int countHelper(int num)
  {
    int isUniqueCount = 0;
    
    for(int i = 0; i < num; i ++)
    {
      vector<bool> visited(10, false);
      
      //for each i in nums, check if its unique
      if(isUnique(i, visited))
        isUniqueCount ++;
    }
    return isUniqueCount;
  }
  
  
    int countNumbersWithUniqueDigits(int n) {
        return countHelper(pow(10,n));
    }
};
