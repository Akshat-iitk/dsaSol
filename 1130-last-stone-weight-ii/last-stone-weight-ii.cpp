class Solution {
public:
int dp[35][1505] ;
int func(int ind , vector<int>&stones , int wt)
{
    int n = stones.size() ;
    if(ind>=n) return 0 ;
    if(dp[ind][wt]!=-1)return dp[ind][wt] ;
    int ans = func(ind+1,stones,wt) ;
    if(stones[ind]<=wt)
    ans = max(ans,stones[ind]+func(ind+1,stones,wt-stones[ind])) ;
    return dp[ind][wt]=ans ;

}
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp)) ;
        int sm = accumulate(stones.begin(),stones.end(),0) ;
        int wt = func(0,stones,sm/2) ;
        return (sm-2*wt) ;
    }
};