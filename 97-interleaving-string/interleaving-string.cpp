class Solution {
public:
static const int N = 1e2+5 ;
int dp[N][N][2*N] ;
bool func(int ind1 , int ind2 , int ind3,string& s1, string& s2, string &s3)
{
    int l1 = s1.size() ;
    int l2 = s2.size() ;
    int l3 = s3.size() ;
    if(ind1==l1 && ind2==l2 && ind3==l3) return true ;
    if(ind3==l3)return false ;
    int ans = false ;
    if(dp[ind1][ind2][ind3]!=-1)return dp[ind1][ind2][ind3] ;
    if(ind1<l1 && s1[ind1]==s3[ind3])
    {
        ans = func(ind1+1,ind2,ind3+1,s1,s2,s3) ;
    }
    if(ind2<l2 && s2[ind2]==s3[ind3])
    {
        ans = ans || func(ind1,ind2+1,ind3+1,s1,s2,s3) ;
    }
    cout<<ind1<<" "<<ind2<<" "<<ind3<<endl ;
    return dp[ind1][ind2][ind3] = ans ;
}
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp)) ;
        return func(0,0,0,s1,s2,s3) ;
    }
};