class Solution {
public:
  
  bool isPalindrome(string s, int l_i, int r_i)
  {    
    while(l_i < r_i)
    {
      if(s[l_i] != s[r_i])
        return false;
      l_i ++;
      r_i --;
    }
    return true;  
  }
  
  
  void partitionHelper(int begin, string s, vector<string> &ir,                 vector<vector<string>> &fr)
  {
    if(begin == s.length())
    {
      fr.push_back(ir);
    }
    {
      for(int i = begin; i < s.length(); i++)
      {
        int l_index = begin;
        int r_index = i;
        if(isPalindrome(s, l_index, r_index))
        {
          //choose
          ir.push_back(s.substr(l_index, r_index - l_index + 1));
          
          //explore
          partitionHelper(i+1, s, ir, fr);
          
          //unchoose
          ir.pop_back();
        }
      }
    }
    return;
  }
  
  
  vector<vector<string>> partition(string s) 
  {   
    vector<string> ir;
    vector<vector<string>> fr;
    
    if(s.empty())
    {
      fr.push_back(ir);
      return fr;
    }
    
    int begin = 0;
    
    partitionHelper(begin, s, ir, fr);
    
    return fr;
  }
};
