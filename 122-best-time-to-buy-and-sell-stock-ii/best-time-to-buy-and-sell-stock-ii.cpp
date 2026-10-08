class Solution {
public:
static const int N = 3*1e4+5 ;
int dp[N][2] ;
int func(int ind , bool buy , vector<int>& prices)
{
    int n = prices.size() ;
    if(ind==n)return 0;
    int ans = 0 ;
    if(dp[ind][buy]!=-1)return dp[ind][buy] ;
    if(buy==1)
    {
        ans = max(ans,func(ind+1,0,prices)-prices[ind]) ;
        ans = max(ans,func(ind+1,1,prices)) ;
    }
    else{
        ans = max(ans,func(ind+1,1,prices)+prices[ind]) ;
        ans = max(ans,func(ind+1,0,prices)) ;
    }
    return dp[ind][buy] = ans ;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp)) ;
        return func(0,1,prices) ;
    }
};