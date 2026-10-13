class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &it : nums)
        {
            it = abs(it);
        }
        int n = nums.size() ;
        long long ans = 0 ;
        sort(nums.begin(),nums.end()) ;
        for(int i = n-1 ; i >= n/2 ; i--)
        {
                ans+= nums[i]*1ll*nums[i] ;
        }
        for(int i = n/2-1 ; i>=0 ;  i--)
        {
            ans-= nums[i]*1ll*nums[i] ;
        }
        return ans ;
    }
};