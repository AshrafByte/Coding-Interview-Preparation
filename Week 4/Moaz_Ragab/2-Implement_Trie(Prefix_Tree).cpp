class Trie {
public:
    bool isleaf;
      Trie * words[26];
    Trie() {
        isleaf=false;
            for (int i = 0; i < 26; ++i) {
            words[i] = NULL; 
        }
    }
  
  
    
    void insert(string word) {
        auto * ptr=this;
        for(auto w:word)
        {
            if(ptr->words[w-'a']==NULL)
            {
                ptr->words[w-'a']=new Trie();
            
            }
             ptr= ptr->words[w-'a'];
        }
        ptr->isleaf=true;
    }
    
    bool search(string word) {
         auto * ptr=this;
        for(auto w:word)
        {
            if(ptr->words[w-'a']==NULL)
            {
              return false;
            
            }
             ptr= ptr->words[w-'a'];
        }
        return ptr->isleaf;

    }
    
    bool startsWith(string prefix) {
             auto * ptr=this;
        for(auto w:prefix)
        {
            if(ptr->words[w-'a']==NULL)
            {
              return false;
            
            }
             ptr= ptr->words[w-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */