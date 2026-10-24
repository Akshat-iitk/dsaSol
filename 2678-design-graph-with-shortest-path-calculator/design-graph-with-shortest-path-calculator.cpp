class Graph {
public:
vector<vector<pair<int,int>>>graph ;
int total ;
    Graph(int n, vector<vector<int>>& edges) {
        total = n ;
        graph.resize(n) ;
        for(auto edge : edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]}) ;
        }
    }
    
    void addEdge(vector<int> edge) {
       graph[edge[0]].push_back({edge[1],edge[2]}) ;
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dis(total,1e9) ;
        dis[node1] = 0 ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
        pq.push({0,node1}) ;
        while(!pq.empty())
        {
            auto curr = pq.top() ;
            pq.pop();
            int currnode = curr.second;
            int currdis = curr.first ;
            if(currnode==node2)return dis[node2] ;
            if(currdis!=dis[currnode])continue ;
            for(auto child : graph[currnode])
            {
                int childnode = child.first ;
                int childwt = child.second ;
                if(dis[childnode]>currdis+childwt)
                {
                    dis[childnode] = currdis+childwt ;
                    pq.push({dis[childnode],childnode}) ;
                }
            }
        }
        if(dis[node2]==1e9)return -1 ;
        return dis[node2] ;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */