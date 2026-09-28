class Solution {
public:
//   long long func(int ind , int n , vector<int>&arr)
//   {
//     if(n<=1)return n ;
//     long long ans = INT_MIN ;
//     int sz = arr.size() ;
//     if(ind>=sz) return 0 ;
//     if(arr[ind]<=n)
//     {
//         ans = max(ans , 1ll*arr[ind]*func(ind,n-arr[ind],arr)) ;
//     } 
//     ans = max(ans,1ll*func(ind+1,n,arr)) ;
//     return ans ;
//   }
    int integerBreak(int n) {
        // vector<int>arr(n+1,0) ;
        // for(int i = 1 ; i<=n ; i++)
        // {
        //     arr[i] = i ;
        // }
        // return func(0,n,arr) ;
       vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;
      for(int i = 0 ; i<n+1 ; i++)
      {
        dp[i][0] = 1 ;
        dp[i][1] = 1 ;
      }
       for(int i = 1 ; i<n ; i++)
       {
        for(int j = 2 ; j<=n ; j++)
        {
            int ans = INT_MIN ;
            if(i<=j)
            {
                ans = max(ans , i*dp[i][j-i]) ;
            }
            ans = max(ans,dp[i-1][j]) ;
            dp[i][j] = ans ;
        }
       } 
       return dp[n-1][n] ;
    }
};