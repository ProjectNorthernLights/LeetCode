class Solution {
public:
    
    void permuteHelper(string &input, vector<string> &m, string &chosen)
    {
      if( input.empty())
      {
         //base insert int a set
         m.push_back(chosen);
      }
      else
      {
        for(int i = 0; i < input.length(); i ++)
        {
          //choose
          char c = input[i];
          chosen = chosen + c;
          input.erase(i,1);
            
          //explore
          permuteHelper(input, m, chosen);
            
          //backtrack
          chosen.erase(chosen.length()-1,1);
          input.insert(i,1,c);
        }
      }
      return;
    }
    
    
    string getPermutation(int n, int k) 
    {
      string result ;
      string chosen ;
        
      string inputstr ;
        
      vector<string> m;
      
      //Convert the n into a string "123.."
      for(int i = 1; i <= n; i++)
      {
        inputstr= inputstr + to_string(i);
      }
        
      //call the helper
      permuteHelper(inputstr, m, chosen);
      
      //now iterate to the kth position 
      for(vector<string>:: iterator itr = m.begin();
          itr < m.end();
          itr++, k--)
      {
        if(k == 1)
        {
          result = *itr;
          return result;
        }
        // take care if k runs 
        else if( k == 0)
        {
          break;
        }
      }
      
      return result;
    }
};
