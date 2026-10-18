class Solution {
public:
int M = 1e9+7 ;
int fac(int n)
{
    if(n==0 || n==1) return 1 ;
    int temp = (n % M *1ll* fac(n-1)%M)%M;
    return temp ;
}
int bexp(int a , int b)
{
    if(b==0)return 1 ;
    int ans = bexp(a,b/2) ;
    ans = (ans * 1ll * ans) % M ;
    if(b%2) ans = (ans * 1ll * a) % M ;
    return (ans)%M ;
}
int func(int n , int r)
{
    if(r==1)return n ;
    if(r==0) return 1 ;
    int nfac = fac(n) ;
    int r1 = fac(r);
    int r2 = fac(n-r) ;
    r = (r1 * 1ll * r2)%M ;
    return ((nfac*1ll*bexp(r,M-2))%M) ;
}
int solve(vector<int>&arr)
{
    int n = arr.size() ;
       if(n<=2) return 1 ;
        vector<int> left ;
        vector<int> right ;
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i]<arr[0])
            left.push_back(arr[i]);
            else right.push_back(arr[i]) ;
        }
   int ans = 1 ;
   ans=(ans%M*1ll*solve(left)%M)%M ;
   ans=(ans%M*1ll*solve(right)%M)%M ;
   int leftnum = left.size() ;
    ans = (ans%M * 1ll * func(n-1,leftnum)%M)%M;
    return ans ;
}
    int numOfWays(vector<int>& nums) {
       return solve(nums)-1;
    }
};