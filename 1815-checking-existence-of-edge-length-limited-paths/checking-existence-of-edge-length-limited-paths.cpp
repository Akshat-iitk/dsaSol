class DSU {
 private :
 vector<int>parent ;
 vector<int>size ;
 public:
 DSU(int n)
 {
    parent.resize(n) ;
    size.resize(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] = i ;
        size[i] = 1 ;
    }
 }   
 int findupar(int u)
 {
    if(parent[u] == u)return u ;
    u = parent[u] ;
    return parent[u] = findupar(u) ;
 }
 void unionbysize(int u , int v)
 {
    u = findupar(u) ;
    v = findupar(v) ;
    if(v==u) return ;
    if(size[v]<size[u])
    {
        size[u]+=size[v] ;
        parent[v] = u ;
    }
    else{
        size[v]+=size[u] ;
        parent[u] = v ;
    }
 }
};
class Solution {
public:
 static bool comp(vector<int>&a , vector<int>&b)
 {
    return a[2]<b[2] ;
 }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n) ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq ;
        vector<bool> ans ;
        for(auto edge : edgeList)
        {
            pq.push({edge[2],{edge[0],edge[1]}}) ;
        }
        int itr = 0 ;
         for(auto &query : queries){
            query.push_back(itr) ;
            itr++ ;
         }
         map<int,bool>mp ;
        sort(queries.begin(),queries.end(),comp);
        for(auto query : queries)
        {
            int u = query[0] ;
            int v = query[1];
            int wt = query[2] ;
            int ind = query[3] ;
            while(!pq.empty())
            {
                auto curr = pq.top() ;
                int currwt = curr.first ;
                int currx = curr.second.first ;
                int curry = curr.second.second ;
                if(currwt<wt)
                {
                    pq.pop() ;
                    dsu.unionbysize(currx,curry) ;
                }
                else{
                    break ;
                }
            }
            if(dsu.findupar(u)==dsu.findupar(v))mp[ind]=(true) ;
            else mp[ind]=(false) ;
        }
        for(auto it : mp)
        {
            ans.push_back(it.second) ;
        }
        return ans ;
    }
};