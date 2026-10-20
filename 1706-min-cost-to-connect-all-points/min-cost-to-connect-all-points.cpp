class Solution {
public:
class DSU{
    private:
    vector<int>parent ;
    vector<int>size ;
    public :
    DSU(int n)
    {
        parent.resize(n+1,0) ;
        size.resize(n+1,1) ;
        for(int i = 0 ; i <= n ;i++)
        {
            parent[i] = i ;
        }
    }
    int finduparent(int u)
    {
        if(parent[u]==u)return u ;
        return parent[u] = finduparent(parent[u]) ;
    }
    void unionBysize(int u , int v)
    {
        u = finduparent(u) ;
        v = finduparent(v) ;
        if(size[u]<=size[v])
        {
            size[v] += size[u] ;
            parent[u] = v ;
        }
        else{
            size[u]+=size[v] ;
            parent[v] = u ;
        }
    }
};
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        DSU dsu(n) ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i!=j)
                {
                    int dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]) ;
                    pq.push({dis,{i,j}}) ;
                }
            }
        }
        int ans = 0 ;
        while(!pq.empty())
        {
            auto curr = pq.top() ;
            pq.pop() ;
            int currwt = curr.first ;
            int x = curr.second.first ;
            int y = curr.second.second;
            if(dsu.finduparent(x)!=dsu.finduparent(y))
            {
                ans+=currwt ;
                dsu.unionBysize(x,y) ;
            }
        }
        return ans ;
    }
};