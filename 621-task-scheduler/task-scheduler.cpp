class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        int tsize = arr.size() ;
        vector<int>vec(26,0) ;
        int most = 0 ;
        int num = 0 ;
        for(auto it : arr)
        {
            vec[it-'A']++ ;
            most = max(vec[it-'A'], most) ;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(vec[i]==most) num++ ;
        }
                if(arr.size()>=((most-1)*(n+1)+num)) return arr.size() ;
                 return ((most-1)*(n+1)+num) ;
    }
};