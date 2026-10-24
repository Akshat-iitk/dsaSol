class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size() ;
        vector<int>dp(n,1) ;
        int ans = 0 ;
        unordered_map<int,int>mp ;
        for(int i = 0; i < n ; i++)
        {
            if(mp.find((arr[i]-diff))!=mp.end())
            {
                dp[i] = max(dp[i],1+dp[mp[arr[i]-diff]]) ;
            }
            mp[arr[i]] = i ;
            ans = max(dp[i],ans) ;
        }
        return ans ;
    }
};