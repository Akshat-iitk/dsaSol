class Solution {
public:
    static const int N = 1e2 + 5;
    int dp[N][N];
    int func(int ind, vector<int>& piles, int M) {
        int n = piles.size();
        if (ind >= n)
            return 0;
        int ans = INT_MIN;
        int sm = 0;
        if (dp[ind][M] != -1)
            return dp[ind][M];
        for (int i = 0; i <= 2 * M - 1; i++) {
            if (ind + i <= n - 1) {
                sm += piles[ind + i];
                ans = max(ans, sm - func(ind + i + 1, piles, max(M, i + 1)));
            } else {
                break;
            }
        }
        return dp[ind][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        int sm = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int j = n; j >= 1; j--) {
                int ans = INT_MIN;
                int sm = 0;
                for (int i = 0; i <= 2 * j - 1; i++) {
                    if (ind + i <= n - 1) {
                        sm += piles[ind + i];
                        ans = max(ans,
                                  sm - dp[ind+i+1][max(j,i+1)]) ;
                    } else {
                        break;
                    }
                }
                dp[ind][j] = ans ;
            }
        }

        // int temp = func(0, piles, 1);
        int temp = dp[0][1] ;
        return ((sm + temp) / 2);
    }
};