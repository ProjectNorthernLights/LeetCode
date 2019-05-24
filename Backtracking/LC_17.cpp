class Solution {
private:
  void helper(int start, string n, unordered_map<string, string> &map, vector<string> &result, string soFar, int len)
  {
    //base
    if(soFar.length() == len){
      result.push_back(soFar);
      return;
    }
    
    //recurse
    string curdigit = n.substr(start,1);
    string curstring = map[curdigit];
    int maxLoop = curstring.length();
    
    for(int i =0; i < maxLoop; ++i)
    {
      //choose
      char choose = curstring[i];
      soFar =  soFar + choose;
      
      //explore
      helper(start+1, n, map, result, soFar, len);
      
      //unchoose
      soFar.erase(soFar.length() -1 , 1);
    }
    
    return;
  }
public:
    vector<string> letterCombinations(string digits)
    {
      unordered_map<string,string> map;
      
      map.emplace("2","abc");
      map.emplace("3","def");
      map.emplace("4","ghi");
      map.emplace("5","jkl");
      map.emplace("6","mno");
      map.emplace("7","pqrs");
      map.emplace("8","tuv");
      map.emplace("9","wxyz");
      
      vector<string> result;
      string soFar = "";
      
      if(digits.length() == 0){
        return result;
      }
      
      helper(0, digits, map, result, soFar, digits.length());
      return result;
    }
