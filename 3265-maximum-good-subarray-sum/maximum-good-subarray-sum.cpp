class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long>mp ;
        long long n = nums.size() ;
        vector<long long>pre(n,0) ;
        pre[0] = nums[0] ;
        mp[nums[0]] = 0 ;
        long long ans = LLONG_MIN ;
        for(long long i = 1 ; i < n ; i++)
        {
            pre[i] = pre[i-1]+nums[i] ;
            if(mp.find(nums[i]+k)!=mp.end())
            {
                long long ind = mp[nums[i]+k] ;
                ans = max(ans,pre[i]-pre[ind]+nums[ind]) ;
            }
             if(mp.find(nums[i]-k)!=mp.end())
            {
                long long ind = mp[nums[i]-k] ;
                ans = max(ans,pre[i]-pre[ind]+nums[ind]) ;
            }
            if(mp.find(nums[i])==mp.end())
            mp[nums[i]] = i ;
            else{
                if(pre[i-1]-pre[mp[nums[i]]]+nums[mp[nums[i]]]<0)mp[nums[i]]= i ;
            }
        }
        if(ans==LLONG_MIN)return 0 ;
        return ans ;
    }
};