class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n,0) ;
        for(auto it : bookings)
        {
            arr[it[0]-1]+=it[2] ;
            if(it[1]!=n)
            {
                arr[it[1]]-=it[2] ;
            }
        }
       for(int i = 1 ; i < n ;  i++)
       {
        arr[i]+=arr[i-1] ;
       }
       return arr ;
    }
};