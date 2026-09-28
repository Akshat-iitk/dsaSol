class Solution {
public:
static const int N = 5*1e4+5 ;
int dp[N] ;
int func(int ind , vector<int>& value)
{
    int n = value.size() ;
    if(ind == n) return 0 ;
    int ans = INT_MIN ;
    if(dp[ind]!=-1)return dp[ind] ;
    ans = max(ans , value[ind]-func(ind+1,value)) ;
    if(ind<n-1)
    {
        
        ans = max(ans,value[ind]+value[ind+1]-func(ind+2,value)) ;
        
    }
    if(ind<n-2)
    {
     
          ans = max(ans,value[ind]+value[ind+1]+value[ind+2]-func(ind+3,value)) ;
    }
return dp[ind]=ans ;
}

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp)) ;
        int ans = func(0,stoneValue) ;
        if(ans==0)return "Tie" ;
        if(ans>0) return "Alice";
        return "Bob" ;
    }
};