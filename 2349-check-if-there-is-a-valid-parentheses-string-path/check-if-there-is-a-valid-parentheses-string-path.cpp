class Solution {
public:
static const int N = 1e2 + 5 ;
int dp[N][N][2*N] ;
bool func(int x , int y , int score , vector<vector<char>>& grid)
{
    int n = grid.size() ;
    int m = grid[0].size() ;
    if(grid[x][y]=='(')score++ ;
    else score--;
    if(score<0) return false ;
    if(x==n-1 && y==m-1)
    {
        if(score==0) return true ;
        return false ;
    }
    if(dp[x][y][score]!=-1)return dp[x][y][score] ;
    bool ans = false ;
    if(x<n-1)
    {
        ans = func(x+1,y,score,grid) ;
    }
    if(y<m-1)
    {
        ans = ans || func(x,y+1,score,grid) ;
    }
    return dp[x][y][score] = ans ;
}
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp)) ;
        return func(0,0,0,grid) ;
    }
};