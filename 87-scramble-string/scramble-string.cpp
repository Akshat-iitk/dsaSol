class Solution {
public:
unordered_map<string,bool>dp ;
bool solve(string &s1 , string &s2)
{
    if(s1.size()!=s2.size())return false ;
    if(s1==s2)return true ;
    bool ans = false ;
    int n = s1.size() ;
    string check = s1+"-"+s2 ;
    if(dp.find(check)!=dp.end())return dp[check] ;
    for(int i = 0; i < n-1 ; i++)
    {
            string temp1 = s1.substr(0,i+1) ;
            string temp2 = s2.substr(0,i+1) ;
            string temp3 = s1.substr(i+1,n-i-1);
            string temp4 = s2.substr(i+1,n-i-1) ;
         ans = solve(temp1,temp2) && solve(temp3,temp4) ;
        if(ans) return dp[check] = true ;
        temp1 = s1.substr(i+1,n-i-1) ;
        temp2 = s2.substr(0,n-i-1) ;
        temp3 = s1.substr(0,i+1) ;
        temp4 = s2.substr(n-i-1,i+1) ;
        ans = solve(temp1,temp2) && solve(temp3,temp4) ;
        if(ans)return dp[check] = true ;
    }
    return dp[check] = false;
}
    bool isScramble(string s1, string s2) {
        int n = s1.size() ;
        int m = s2.size() ;
     return solve(s1 ,s2) ;
    }
};