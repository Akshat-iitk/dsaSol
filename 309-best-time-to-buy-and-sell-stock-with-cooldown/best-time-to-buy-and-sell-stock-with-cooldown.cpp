class Solution {
public:
int dp[5005][2][2] ;
int func(int ind , vector<int>&prices , int flag , int cool)
{
    int n = prices.size() ;
    if(ind>=n) return 0 ;
    if(dp[ind][cool][flag]!=-1)return dp[ind][cool][flag] ;
    int temp = func(ind+1,prices,flag,1) ;
    if(flag==1)
    {
        if(cool==1)
        {
            temp = max(temp , func(ind+1,prices,0,1)-prices[ind]) ;
        }
    }
    else{
        temp = max(temp,prices[ind]+func(ind+1,prices,1,0)) ;
    }
 return dp[ind][cool][flag] = temp ;
    

}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp)) ;
        return func(0,prices,1,1) ;
    }
};