class Solution {
public:
int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>&vis)
{
    int n = grid.size() ;
    int m = grid[0].size() ;
    if(i<0 || i>=n || j < 0 || j>=m || vis[i][j] || grid[i][j]==0) return 0 ;
    vis[i][j] = 1 ;
    int ans = 0 ;
    ans+=grid[i][j] ;
    ans+=dfs(i+1,j,grid,vis) ;
    ans+=dfs(i-1,j,grid,vis) ;
    ans+=dfs(i,j+1,grid,vis) ;
    ans+=dfs(i,j-1,grid,vis) ;
    return ans ;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int ans = 0 ;
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int temp = dfs(i,j,grid,vis) ;
                ans = max(ans,temp) ;
            }
        }
        return ans ;
    }
};