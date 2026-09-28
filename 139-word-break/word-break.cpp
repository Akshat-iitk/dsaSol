class Solution {
public:
static const int N = 305;
int dp[N] ;
    bool func(int ind, string& s, vector<string>& wd,
              unordered_set<string>& hash) {
        int n = s.size();
        if (ind >= n)
            return true;
            if(dp[ind]!=-1)return dp[ind] ;
        for (int take = 1; take <= n; take++) {
            string sub = s.substr(ind, take);
            if (hash.find(sub) != hash.end() &&
                func(ind + take, s, wd, hash) == true) {
                return dp[ind] = true;
            }
        }
        return dp[ind] =  false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size();
        unordered_set<string> hash;
        memset(dp,-1,sizeof(dp)) ;
        for (auto& it : wd) {
            hash.insert(it);
        }
        return func(0, s, wd , hash);
    }
};