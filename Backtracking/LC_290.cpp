class Solution {
public:
    bool wordPattern(string pattern, string str) {
      
      unordered_map<char, string> hashmap;
      unordered_set<string> wordsSeenSoFar;
      
      //stringstram object
      stringstream s(str);
      string word;
      
      for(int i = 0; i < pattern.length(); i++)
      {
        //if all the words are used up, return false
        //since the # of chars in pattern should atch the number of
        //words in the string
        if(!(s >> word))
          return false;
        
        
        char c = pattern[i];

        //if char is not present in hashmap, add it
        //else if it already exists, check if it maps
        //to the same word
        
        if(hashmap.find(c) == hashmap.end())
          hashmap.emplace(c, word);
        else{
          unordered_map<char, string> :: iterator itr;
          itr = hashmap.find(c);
          string value = itr->second;
          
          if(value != word)
            return false;
          else
            continue;
        }
          
        //If 2 different chars in pattern map to same word, return false
        if(wordsSeenSoFar.count(word) == 0)
          wordsSeenSoFar.insert(word);
        else
          return false;

        }
      
      //if youve reached this point, then pattern is used up,
      //check if string is used up too or not
      if(s >> word)
        return false;
      else
        return true;
    }
};
