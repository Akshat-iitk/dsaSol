class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>> st ;
        int n = nums.size() ;
        int i = 0 , j = 0 ;
    vector<int> ans  ;
        while(j<n)
        {
            st.insert({-1*nums[j],j}) ;
            if(j-i+1==k)
            {
                auto node = *st.begin() ;
                ans.push_back(-1*(node.first)) ;
                st.erase({-1*nums[i],i}) ;
                i++ ;
            }
            j++ ;
        }
    return ans ;
    }
};