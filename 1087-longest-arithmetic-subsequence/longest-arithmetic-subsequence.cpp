class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<unordered_map<int, int>> dp(n);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 2;

                auto it = dp[j].find(diff);

                if (it != dp[j].end()) {
                    len = it->second + 1;
                }

                dp[i][diff] = max(dp[i][diff], len);
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};