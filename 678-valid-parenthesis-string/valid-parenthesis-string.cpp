class Solution {
public:
static const int N = 1e3+5 ;
int dp[N][N] ;
bool func(int ind , int abs , string &s)
{
    int n = s.size() ;
    if(ind==n)
    {
        if(abs==0)return true ;
        return false ;
    }

    bool ans = false ;
    if(abs<0) return false ;
    if(dp[ind][abs]!=-1)return dp[ind][abs] ; 
    if(s[ind]=='(') ans = ans || func(ind+1,abs+1,s) ;
    if(s[ind]==')') ans = ans || func(ind+1,abs-1,s) ;
    if(s[ind]=='*')
    {
        ans = ans || func(ind+1,abs,s) ;
        ans = ans || func(ind+1,abs-1,s) ;
        ans = ans || func(ind+1,abs+1,s) ;
    }
    return dp[ind][abs] = ans ;
}
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp)) ;
        return func(0,0,s) ;
    }
};