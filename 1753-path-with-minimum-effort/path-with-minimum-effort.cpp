class Solution {
public:
bool isvalid(int x , int y , int n , int m)
{
    return (x>=0 && x<n && y>=0 && y<m );
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ;
        int m = heights[0].size() ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq ;
        vector<vector<int>>dis(n,vector<int>(m,1e9)) ;
        vector<pair<int,int>>moves = {{1,0},{-1,0},{0,1},{0,-1}} ; 
        pq.push({0,{0,0}}) ;
        dis[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top() ;
            pq.pop() ;
            int currwt = curr.first ;
            int currx = curr.second.first ;
            int curry = curr.second.second ;
            if(currx==n-1 && curry == m-1)
            return dis[currx][curry] ;
            if(dis[currx][curry]!=currwt)continue ;
        for(auto move: moves)
        {
            int newx = move.first + currx ;
            int newy = move.second+ curry ;
            if(isvalid(newx,newy,n,m))
            {
                if(dis[newx][newy]>max(dis[currx][curry],abs(heights[newx][newy]-heights[currx][curry])))
                {
                    dis[newx][newy] = max(dis[currx][curry],abs(heights[newx][newy]-heights[currx][curry])) ;
                    pq.push({dis[newx][newy],{newx,newy}}) ;
                }
            }
        }
        }
        return -1 ;
    }
};