
class Trie {
public:
struct Node{
    Node* children[26] ;
    bool end ;   
 } ;
Node* getNode()
{
    Node* newNode = new Node() ;
    newNode->end = false;
    for(int i = 0 ; i < 26 ;i++)
    {
        newNode->children[i] = NULL ;
    }
    return newNode ;
}

Node* root ;
    Trie() {
        root = getNode() ;
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size() ;
        for(int i = 0 ; i < n ;i++)
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
    
    bool search(string word) {
        Node* node = root ;
        for(int i = 0 ; i<word.size() ; i++)
        {
            int ind = word[i]-'a' ;
            if(node->children[ind]==NULL)return false ;
            node = node->children[ind] ;
        }
        return(node->end) ;
    }
    
    bool startsWith(string prefix) {
         Node* node = root ;
        for(int i = 0 ; i<prefix.size() ; i++)
        {
            int ind = prefix[i]-'a' ;
            if(node->children[ind]==NULL)return false ;
            node = node->children[ind] ;
        }
        return true  ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */