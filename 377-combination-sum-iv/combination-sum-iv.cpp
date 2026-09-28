class Solution {
public:
static const int N = 1e3+5 ;
int dp [205][N] ;
    int func(int ind, int target, vector<int>& nums) {
        int n = nums.size();

        if (ind >= n && target == 0)
            return 1;
         if (ind>=n)
        return 0;
        if(dp[ind][target]!=-1)return dp[ind][target] ;
        int ans = 0;
        if (nums[ind] <= target)
            ans += func(0, target - nums[ind], nums);
        ans += func(ind + 1, target, nums);
        return dp[ind][target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1 , sizeof(dp)) ;
        return func(0, target, nums);
    }
};