class Solution {
public:
bool isvalid(int x , int y , int n , int m)
{
    return (x>=0 && x<n && y>=0 && y<m) ;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq ;
        vector<vector<int>>dis(n,vector<int>(m,1e5)) ;
        vector<vector<int>>movement ={{0,1},{0,-1},{1,0},{-1,0}} ;
        dis[0][0] = grid[0][0] ;
        pq.push({dis[0][0],{0,0}}) ;
        while(!pq.empty())
        {
            auto curr = pq.top() ;
            pq.pop() ;
            int currdis = curr.first ;
            int currx = curr.second.first ;
            int curry = curr.second.second ;
            if(currx==n-1 && curry == m-1) return dis[n-1][m-1] ;
            for(auto move : movement)
            {
                int newx = move[0] + currx ;
                int newy = move[1]+ curry ;

                if(isvalid(newx,newy,n,m))
                {
                    if(dis[newx][newy]>max(grid[newx][newy],dis[currx][curry])){
                        dis[newx][newy] = max(grid[newx][newy],dis[currx][curry]) ;
                        pq.push({dis[newx][newy],{newx,newy}}) ;
                    }
                }
            }
        }
        return -1 ;
    }
};