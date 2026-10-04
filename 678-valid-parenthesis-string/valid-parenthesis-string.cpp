class Solution {
public:
    static const int N = 1e3 + 5;
    int dp[N][N];
    bool func(int ind, int abs, string& s) {
        int n = s.size();
        if (ind == n) {
            if (abs == 0)
                return true;
            return false;
        }

        bool ans = false;
        if (abs < 0)
            return false;
        if (dp[ind][abs] != -1)
            return dp[ind][abs];
        if (s[ind] == '(')
            ans = ans || func(ind + 1, abs + 1, s);
        if (s[ind] == ')')
            ans = ans || func(ind + 1, abs - 1, s);
        if (s[ind] == '*') {
            ans = ans || func(ind + 1, abs, s);
            ans = ans || func(ind + 1, abs - 1, s);
            ans = ans || func(ind + 1, abs + 1, s);
        }
        return dp[ind][abs] = ans;
    }
    bool checkValidString(string s) {
        // memset(dp,-1,sizeof(dp)) ;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                bool ans = false;
                if (s[i] == '(')
                    ans = ans || dp[i + 1][j + 1];
                if (s[i] == ')' && j != 0)
                    ans = ans || dp[i + 1][j - 1];
                if (s[i] == '*') {
                    ans = ans || dp[i + 1][j];
                    ans = ans || dp[i + 1][j + 1];
                    if (j != 0)
                        ans = ans || dp[i + 1][j - 1];
                }
                dp[i][j] = ans;
            }
        }
        // return func(0,0,s) ;
        return dp[0][0];
    }
};