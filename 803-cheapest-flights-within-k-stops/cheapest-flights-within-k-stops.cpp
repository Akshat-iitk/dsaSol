class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n] ;
        for(auto & it : flights)
        {
            graph[it[0]].push_back({it[1],it[2]}) ;
        }
        vector<int> fare(n,1e9) ;
        queue<pair<int,pair<int,int>>> pq ;
       queue<pair<int,pair<int,int>>> q ;
          fare[src] = 0 ;
     pq.push({0,{-1,src}}) ;
     while(!pq.empty())
     {
           auto it = pq.front() ;
        //    q.erase(q.begin());
            pq.pop() ;
           int node_fare = it.first ;
           int node_dis = it.second.first ;
           int node = it.second.second ;

           
        //    if(node==dst && node_dis<=k) return node_fare ; 
        //    if(node==dst && node_dis>k+1) continue ; /
           for(auto &child : graph[node])
           {
               int curr_node = child.first ;
               int curr_fare = child.second ;
               if(node_fare+curr_fare<=fare[curr_node] && node_dis<k)
               {
                   fare[curr_node]=node_fare+curr_fare ;
                   pq.push({fare[curr_node],{node_dis+1,curr_node}}) ;
               }
           }
     }
if(fare[dst]==1e9) return -1 ;
return fare[dst] ;
    }
};