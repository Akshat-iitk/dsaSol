class Solution {
public:
    int numSquares(int n) {
        vector<int>sq(102) ;
        for(int i = 1 ; i <=101 ; i++)
        {
            sq[i] = i*i ;
        }
        vector<vector<int>>dp(105,vector<int>(n+1,1e9)) ;
        for(int i = 0 ; i <= 104 ; i++)
        {
            dp[i][0] = 0 ;
        }
        for(int i = 1 ; i<=101 ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                int ans = INT_MAX ;
                 if(sq[i]<=j)
            {
                ans = min(ans,1 + dp[i][j-sq[i]]) ;
            }
            ans = min(ans,dp[i-1][j]) ;
            dp[i][j] = ans ;
            } 
        }
        return dp[101][n] ;
    }
};