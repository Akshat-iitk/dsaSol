class Solution {
public:
bool func(int k , int h , vector<int>&piles)
{
    long long flag = 0 ;
    for(auto it : piles)
    {
        if(it%k==0)flag=flag+1ll*it/k ;
        else flag=flag + 1ll*it/k+1 ;
    }
    if(flag>h)return false ;
    return true ;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = -1 ;
        for(auto it : piles)
        {
            high = max(high , it);
        }
        int ans = -1 ;
            int low = 1 ;
            while(low<=high)
            {
                int mid = low + (high-low)/2 ;
                if(func(mid,h,piles))
                {
                    ans = mid ;
                    high = mid-1 ;
                }
                else{
                    low = mid+1 ;
                }
            }
            return ans ;
    }

};