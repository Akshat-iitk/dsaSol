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
        // memset(dp,-1,sizeof(dp)) ;
        vector<int>dp(n+1,false) ;
        dp[n] = true ;
        
        for (auto& it : wd) {
            hash.insert(it);
        }
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int take = 1 ; take<=n ; take++)
            {
                string sub = s.substr(i,take) ;
                if(hash.find(sub)!=hash.end())
                {
                    if(i+take>=n || dp[i+take]==true)
                    {
                        dp[i] = true ;
                        break ;
                    }
                }
            }
        }
        return dp[0] ;
        // return func(0, s, wd , hash);
    }
};