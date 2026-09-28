class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sm = accumulate(nums.begin() , nums.end(), 0) ;
        int temp = (sm+target);
        if(temp<0)return 0 ;
        if(temp%2!=0)return 0 ;
        temp = temp/2 ;
        int n = nums.size() ;
        vector<vector<int>>dp(n+1,vector<int>(temp+1,0)) ;
        dp[0][0] = 1 ;
        // for(int i = 0 ; i<=n ; i++)
        // dp[i][0] = 1 ; 
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 0 ; j<=temp ; j++)
            {
                dp[i][j] = dp[i-1][j] ;
                if(nums[i-1]<=j)
                {
                    dp[i][j] +=dp[i-1][j-nums[i-1]] ;
                }
            }
        }
        return dp[n][temp] ;
    }
};