class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()) ;
        int currstart = -1  ;
        int currend = -1 ;
        vector<vector<int>>ans ;
        for(auto it : intervals)
        {
            int start = it[0] ;
            int end = it[1] ;
            if(currstart==-1)
            {
                currstart=start ;
                currend = end ;
            }
            else{
                if(currend<start)
                {
                    ans.push_back({currstart,currend}) ;
                    currstart = start ;
                    currend = end ;
                }
                else{
                    currend = max(currend,end) ;
                }
            }
        }
        ans.push_back({currstart,currend}) ;
        return ans ;
    }
};