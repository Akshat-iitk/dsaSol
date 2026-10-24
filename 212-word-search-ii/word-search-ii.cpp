class Solution {
public:
struct Node{
string word ;
bool end ;
Node* children[26] ;
} ;
Node* getNode()
{
    Node *node = new Node() ;
    node->word = "" ;
    node->end = false ;
    for(int i = 0 ; i< 26 ;i++)
    {
        node->children[i] = NULL ;
    }
    return node ;
}
void insert(string &word , Node* root)
{
    Node *node = root ;
    for(int i = 0 ; i <word.size() ; i++)
    {
        int ind = word[i]-'a' ;
        if(node->children[ind]==NULL)
        {
            node->children[ind] = getNode() ;
        }
        node = node->children[ind] ;
    }
    node->word = word ;
    node->end = true ;
}
 vector<vector<int>>movements = {{-1,0},{1,0},{0,1},{0,-1}} ;
void func(int i , int  j , vector<vector<char>>& board , Node* root ,  vector<string>&ans)
{
    int n = board.size() ;
    int m = board[0].size() ;
    if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='V' || root->children[board[i][j]-'a']==NULL) return ;
    Node *node = root ;
    char ch = board[i][j] ;
    board[i][j] = 'V' ;
    node = node->children[ch-'a'] ;
    if(node->end==true)
    {
        ans.push_back(node->word) ;
        node->end = false ;
    }
    for(auto &move:movements)
    {
        int newi = i + move[0] ;
        int newj = j + move[1] ;
        func(newi,newj,board,node,ans) ;
    }
    board[i][j] = ch ;
    return ;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans ;
        int n = board.size() ;
        int m = board[0].size() ;
        Node* root = getNode() ;
        for(auto &word : words)
        {
            insert(word,root) ;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(root->children[board[i][j]-'a']!=NULL)
                func(i,j,board,root,ans) ;
            }
        }
        return ans ;
    }
};