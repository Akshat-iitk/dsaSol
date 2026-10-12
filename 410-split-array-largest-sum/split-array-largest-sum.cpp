class Solution {
public:
 int func(int mxval , vector<int>& arr )
 {
    int st = 1 ;
    int val = 0 ;
     int n = arr.size() ;
    for(int i = 0 ; i < n ;i++)
    {
        if(val+arr[i]<=mxval)
        {
            val+=arr[i] ;
        }
        else{
            st++ ;
            val = arr[i] ;
        }
    }
        return st ;
 }
    int splitArray(vector<int>& arr, int k) {
          int n = arr.size() ;
        long long high = 0 ;
        long long low = -1 ;
        long long ans = 0 ;
       
        for(auto it : arr)
        {
            high +=it ;
            low = max(low,1ll*it) ;
        }
        while(low<=high)
        {
            long long mid = low + (high-low)/2 ;
            if(func(mid , arr)>k){
                low = mid + 1 ;
            }
            else{
                high = mid - 1 ;
                ans = mid ;
            }
        }
        return ans ;
    }
};