class Solution {
public:
int M = 1e9+7 ;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n) ;
        for(auto it : roads)
        {
            graph[it[1]].push_back({it[0],it[2]});
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<long long>dis(n,1e15) ;
        vector<long long>num(n,0) ;
        num[0] = 1 ;
        dis[0] = 0 ;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq ;
        pq.push({0,0}) ;
        while(!pq.empty())
        {
            auto curr = pq.top();
            long long currnode = curr.second ;
            long long currdis = curr.first ;
            pq.pop() ;
            if(currdis>dis[currnode])continue ;
           for(auto child : graph[currnode])
           {
             long long childnode = child.first ;
             long long childwt = child.second ;
             if(1ll*dis[childnode]>1ll*dis[currnode]+1ll*childwt)
             {
                dis[childnode] = dis[currnode]+childwt ;
                num[childnode] = (num[currnode])%M ;
                pq.push({dis[childnode],childnode}) ;
             }
             else if(1ll*dis[childnode]==1ll*dis[currnode]+1ll*childwt)
             {
                num[childnode]= (num[childnode]%M+num[currnode]%M)%M;
             }
           } 
        }
        return num[n-1]%M ;
    }
};