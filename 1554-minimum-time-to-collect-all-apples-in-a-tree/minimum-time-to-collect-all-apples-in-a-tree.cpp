class Solution {
public:
pair<int,bool> dfs(int node , vector<vector<int>>&graph ,  vector<int>&vis , vector<bool>& hasApple)
{
    vis[node]= true ;
    int ans = 0 ;
    bool check = false ;
    if(hasApple[node]==true) check = true ;
    for(auto child : graph[node])
    {
        if(!vis[child])
        {
            auto childcheck = dfs(child,graph,vis,hasApple) ;
            if(childcheck.second==true)
            {
            check = true ;
            ans+=2;
            } 
            ans+=childcheck.first ;
        }
    }
    return {ans,check} ;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>graph(n) ;
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]) ;
            graph[edge[1]].push_back(edge[0]) ;
        }
        vector<int>vis(n,0) ;
        auto ans = dfs(0,graph,vis,hasApple) ;
        return ans.first ;
    }
};