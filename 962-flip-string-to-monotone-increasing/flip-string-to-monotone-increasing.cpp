class Solution {
public:
static const int N = 1e5+5 ;
int dp[N][2] ;
int flip(int i , int flag , string &s)
{
    int n = s.size() ;
    if(i==n)return 0 ;
    int ans = INT_MAX ;
    if(dp[i][flag]!=-1)return dp[i][flag] ;
    if(flag==0)
    {
        if(s[i]=='1')
        ans = min(ans,1+min(flip(i+1,1,s),flip(i+1,0,s))) ;
        else{
            ans = min(ans,min(flip(i+1,1,s),flip(i+1,0,s))) ;
        }
    }
    else{
        if(s[i]=='1')
        {
            ans = min(ans,flip(i+1,1,s)) ;
        }
        else{
            ans = min(ans,1+flip(i+1,1,s)) ;
        }
    }
    return dp[i][flag]=ans ;
}
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp)) ;
        return min(flip(0,0,s),flip(0,1,s)) ;
    }
};