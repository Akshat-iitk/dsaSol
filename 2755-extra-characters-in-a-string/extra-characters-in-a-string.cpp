class Solution {
public:
unordered_set<string>st ;
static const int N = 55 ;
int dp[N] ;
int func(int i , string&s , vector<string>&dic)
{
    int n = s.size() ;
    if(i==n)return 0 ;
    int ans = INT_MAX ;
    if(dp[i]!=-1)return dp[i] ;
    ans = min(ans,1+func(i+1,s,dic)) ;
    for(int j = i ; j < n ; j++)
    {
        if(st.find(s.substr(i,j-i+1))!=st.end())
        {
            ans = min(ans,func(j+1,s,dic)) ;
        }
    }
    return dp[i] = ans ;
}
    int minExtraChar(string s, vector<string>& dic) {
        memset(dp,-1,sizeof(dp)) ;
        for(auto &it : dic)
        {
            st.insert(it) ;
        }
        return func(0,s,dic) ;
    }
};