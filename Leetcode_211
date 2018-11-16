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
    
  void searchHelper(TrieNode *root, string &word){
      TrieNode *temp = root;
      map<char, TrieNode*> :: iterator itr;
      for(int i =0; i < word.length(); i++)
      {
          char c =  word[i];
          if( c == '.'){
              if(temp->m.size() != 0){
                  temp
              }
          }
              
          itr = temp->m.find(c);
          
          if(itr == temp->m.end()){
              return false;
          }
          temp = temp->m[c];
      }
      return temp->endOfWord;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
