class WordDictionary {
public:
    
    struct TrieNode{
        bool endOfWord;
        map<char, TrieNode*> m;
    };
    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
      root = getNode();    
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWordHelper(root, word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(root, word);
    }
    
private:
  TrieNode *getNode(void){
      TrieNode *newnode = new TrieNode;
      newnode->endOfWord = false;
      return newnode;
  }
    
  void addWordHelper(TrieNode *root, string &word){
      TrieNode *temp = root;
      map<char, TrieNode*> :: iterator itr;
      for(int i =0; i < word.length(); i++)
      {
          char c =  word[i];
          itr = temp->m.find(c);
          
          if(itr == temp->m.end()){
              temp->m[c] = getNode();
          }
          temp = temp->m[c];
      }
      temp->endOfWord = true;
  }
    
  bool searchHelper(TrieNode *root, string word)
  {   
      TrieNode *temp = root;
      map<char, TrieNode*> :: iterator itr;
    
      if(word.empty())
      {
        if(temp->endOfWord)
          return true;
        else
          return false;
      }
    
      for(int i =0; i < word.length(); i++)
      {
        //choose
        char c =  word[i];
        
        if(c == '.')
        {
          //ASCII a is 97 , so on..
          for(int j = 97; j < 123; j++)
          {  
            if(temp->m[(char)j])
            {
              //choose
              string old_word = word;
              word = word.substr(i+1);
              
              //explore
              if(searchHelper(temp->m[(char)j], word))
                return true;
                 
              //backtrack
              word = old_word;
            }
          }
        
          //if after all possible children have been explored, still
          //true is not returned, then return false
          return false;
        }
        else
        {
          itr = temp->m.find(c);
          if(itr == temp->m.end())
          {
            return false;
          }else
          {
            temp = temp->m[c];
          }
        }
      }
      return temp->endOfWord ;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
