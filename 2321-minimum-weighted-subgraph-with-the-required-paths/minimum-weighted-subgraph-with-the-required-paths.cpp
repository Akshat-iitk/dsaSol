class Solution {
public:
    void solve(long long src, vector<vector<pair<long long, long long>>>& graph,
               vector<long long>& dis) {
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>pq;
        pq.push({0, src});
        dis[src] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            long long currnode = curr.second;
            long long currwt = curr.first;
            if(currwt != dis[currnode]) continue ;
            for (auto child : graph[currnode]) {
                long long childnode = child.first;
                long long wt = child.second;
                if (dis[childnode] == -1 || dis[childnode] > dis[currnode] + wt) {
                    dis[childnode] = dis[currnode] + wt;
                    pq.push({dis[childnode], childnode});
                }
            }
        }
        return;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<vector<pair<long long, long long>>> graph(n);
        vector<vector<pair<long long, long long>>> graph2(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph2[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<long long> dis1(n, -1);
        vector<long long> dis2(n, -1);
        vector<long long> dis3(n, -1);
        solve(src1, graph, dis1);
        solve(src2, graph, dis2);
        solve(dest, graph2, dis3);
        long long ans = LLONG_MAX  ;
        for (long long i = 0; i < n; i++) {
            if (dis1[i] != -1 && dis2[i] != -1 && dis3[i] != -1) {
                ans = min(ans, dis1[i] + dis2[i] + dis3[i]);
            }
        }
        if(ans==LLONG_MAX) return -1 ;
        return ans;
    }
};