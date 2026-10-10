class Solution {
public:
    int mySqrt(int x) {
        long long low  = 0 ;
        long long high = x ;
        while(low<=high)
        {
            long long mid = low + (high-low)/2 ;

            if(mid*1ll*mid==1ll*x)return mid ;
            if(mid*1ll*mid>x)high = mid-1 ;
            else low = mid+1 ;
        }
        return high ;
    }
};