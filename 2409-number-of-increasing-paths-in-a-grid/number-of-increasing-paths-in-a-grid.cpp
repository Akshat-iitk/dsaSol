class Solution {
public:
int M = 1e9+7 ;
static const int N = 1e3+5 ;
long long dp[N][N] ;
bool isvalid(int i , int j , int n , int m)
{
    return i>=0 && i < n && j>=0 && j< m ;
}
vector<vector<int>>movements = {{1,0},{-1,0},{0,1},{0,-1}} ;
int func(int i , int j , vector<vector<int>>& grid)
{
    int n = grid.size() ;
    int m = grid[0].size() ;
    long long temp = 1 ;
    if(dp[i][j]!=-1)return dp[i][j] ;
    for(auto &move:movements)
    {
        int newi = move[0]+i ;
        int newj = move[1]+j ;
        if(isvalid(newi,newj , n , m) && grid[newi][newj]<grid[i][j])
        {
            temp= (temp%M + func(newi,newj,grid)%M )%M;
        }
    }
    return dp[i][j] =  temp ;
}
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        long long ans = 0 ;
        memset(dp,-1,sizeof(dp)) ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                ans=(ans%M+func(i,j,grid)%M)%M ;
            }
        }
        return ans ;
    }
};