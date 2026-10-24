class WordDictionary {
public:
struct Node{
    bool end ;
    Node* children[26] ;
} ;
Node* getNode()
{
    Node* node = new Node() ;
    node->end = false ;
    for(int i = 0 ; i < 26 ; i++)
    {
        node->children[i] = NULL ;
    }
    return node ;
}
Node* root ;
    WordDictionary() {
        root = getNode() ;
    }
    
    void addWord(string word) {
        Node *node = root ;
        for(int i = 0 ; i < word.size() ; i ++)
        {
            int ind = word[i]-'a' ;
            if(node->children[ind]==NULL)
            {
                node->children[ind] = getNode() ;
            }
            node = node->children[ind] ;
        }
        node->end = true ;
    }
    
    bool searchfunc(Node* root ,string word) {
        Node * node = root ;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(word[i]=='.')
            {
                for(int ch = 0 ; ch<26 ; ch++)
                {
                    if(node->children[ch]!=NULL)
                    {
                        if(searchfunc(node->children[ch] , word.substr(i+1))==true)    return true ;
                    }
                }
                return false ;
            }
            else{
                int ind = word[i] - 'a' ;
                if(node->children[ind]==NULL) return false ;
                node = node->children[ind] ;
            }
        }
        return(node!=NULL && node->end==true) ;
    }
    bool search(string word)
    {
        Node* node = root ;
        return searchfunc(node,word) ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */