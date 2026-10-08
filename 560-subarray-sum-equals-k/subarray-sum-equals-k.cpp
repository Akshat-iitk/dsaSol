class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;
        mp[0]++ ;
        
        int sm = 0 ;
        int ans = 0 ;
        for(auto it : nums)
        {
            sm+=it ;
            if(mp.find(sm-k)!=mp.end()) 
            {
                ans+=mp[sm-k] ;
            }
            mp[sm]++ ;
        }
        return ans; 
    }
};