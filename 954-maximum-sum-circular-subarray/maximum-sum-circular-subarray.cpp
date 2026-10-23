class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int ans = 0 ;
        int mx = INT_MIN ;
        int mn = INT_MAX ;
        int mxsum = 0 ;
        int mnsum = 0 ;
        int n = arr.size() ;
        int total = 0 ;
        for(auto it : arr)
        {
            if(mxsum+it<it) mxsum = it ;
            else mxsum +=it ;
            if(mnsum+it>it) mnsum = it ;
            else mnsum+=it ;
            mx = max(mxsum,mx) ;
            mn = min(mnsum,mn) ;
            total+=it ;
        }
        if(mn==total)return mx ;
        else return max(total-mn,mx) ;
    }
};