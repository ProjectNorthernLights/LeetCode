class Trie {
public:
    #define MAX_ALPHABET 26
    
    struct TrieNode{
      bool endOfWord;
      TrieNode *children[MAX_ALPHABET];
    };
    
    TrieNode *root ;
    
    /** Initialize your data structure here. */
    Trie() 
    {
      root = getNode(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertHelper(word, root);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchHelper(word, root);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixHelper(prefix, root);
    }
    
private:
    
    TrieNode *getNode(void){
        TrieNode *newnode = new TrieNode;
        newnode->endOfWord = false;
        
        for(int i = 0; i < MAX_ALPHABET; i++)
            newnode->children[i] = nullptr;
        
        return newnode; 
    }
    
    void insertHelper(string word, TrieNode *root){
        TrieNode *temp = root;
        for(int i = 0 ; i < word.length(); i ++){
            int index = word[i] - 'a';
            if(!temp->children[index])
            {
              temp->children[index] = getNode();     
            }
            temp = temp->children[index];   
        }
        
        temp->endOfWord = true;
    }
    
    bool searchHelper(string word, TrieNode *root){
        TrieNode *temp = root;
        for(int i = 0; i < word.length(); i ++){
            int index = word[i] - 'a';
            if(!temp->children[index])
                return false;
            else
                temp = temp->children[index];
        }
        return (temp->endOfWord);
    }
    
    bool prefixHelper(string prefix, TrieNode *root){
        TrieNode *temp = root;
        for(int i = 0; i < prefix.length(); i ++){
            int index = prefix[i] - 'a';
            if(!temp->children[index])
                return false;
            else
                temp = temp->children[index];
        }
        return true ;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
