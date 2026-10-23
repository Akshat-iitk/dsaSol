class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n+1,0) ;
        for(auto it : bookings)
        {
            arr[it[0]]+=it[2] ;
            if(it[1]!=n)
            {
                arr[it[1]+1]-=it[2] ;
            }
        }
        vector<int>ans ;
        ans.push_back(arr[1]);
        for(int i = 2 ; i <= n ; i++)
        {
            arr[i]+=arr[i-1]   ;
            ans.push_back(arr[i]) ;

                }
                return ans; 
    }
};