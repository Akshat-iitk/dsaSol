class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = -1 ;
        int ans = 0 ;
        for(auto it : prices)
        {
            if(mn == -1) mn = it;
            else{
                if(it>mn)ans = max(ans,it-mn) ;
                else{
                    mn = it ;
                }
            }
        }
        return ans ;
    }
};