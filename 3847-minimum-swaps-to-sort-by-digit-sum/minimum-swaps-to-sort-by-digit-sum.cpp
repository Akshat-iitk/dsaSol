class Solution {
public:
static bool comp(pair<int,int>&a ,pair<int,int>&b)
{
    if(a.first!=b.first) return a.first<b.first ;
    return (a.second<b.second) ;
}
    int minSwaps(vector<int>& arr) {
        int n = arr.size() ;
        vector<pair<int,int>>hash;
        unordered_map<int,int>mp ;
        for(int i = 0 ; i < n ; i++)
        {
            mp[arr[i]] = i ;
        }
        for(int i = 0 ; i<n ; i++)
        {
            int flag = arr[i] ;
            int sm = 0 ;
            while(flag)
            {
                sm+=flag%10 ;
                flag/=10 ;
            }
            hash.push_back({sm,arr[i]}) ;
        }
        sort(hash.begin(),hash.end(),comp) ;
        int ans = 0 ;
       for(int i = 0 ; i < n ; i++)
       {
        int ind = mp[hash[i].second] ;
        if(ind==i)continue ;
        swap(arr[i],arr[ind]) ;
        mp[arr[i]] = i ;
        mp[arr[ind]] = ind ;
        ans++ ;
       }
       return ans ;
    }
};