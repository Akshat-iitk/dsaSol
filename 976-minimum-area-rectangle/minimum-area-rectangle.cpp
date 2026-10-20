class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>>st ;
        sort(points.begin(),points.end()) ;
        for(auto it : points)
        {
            st.insert({it[0],it[1]}) ;
        }
        int n = points.size() ;
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int x1 = points[i][0] ;
                int y1 = points[i][1] ;
                int x2 = points[j][0] ;
                int y2 = points[j][1] ;
                if(x1==x2 || y1==y2) continue ;
                if(st.find({x1,y2})!=st.end() && st.find({x2,y1})!=st.end())
                {
                    ans = min(ans,(abs(x1-x2)*abs(y1-y2))) ;
                }
            }
        }
        if(ans==INT_MAX)return 0 ;
        return ans ;
    }
};