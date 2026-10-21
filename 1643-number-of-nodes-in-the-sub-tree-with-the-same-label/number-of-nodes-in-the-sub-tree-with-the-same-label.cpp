class Solution {
public:
void dfs(int node ,  vector<vector<int>>&graph ,  vector<int>&vis , string &lable , vector<vector<int>>&num)
{
    vis[node] = true ;
    num[node][lable[node]-'a']++ ;
    for(auto child : graph[node])
    {
        if(!vis[child])
        {
            dfs(child,graph,vis,lable,num) ;
            for(int i = 0 ; i < 26 ; i++)
                num[node][i]+=num[child][i] ;
        }
    }
    return ;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>num(n,vector<int>(26,0)) ;
        vector<vector<int>>graph(n) ;
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]) ;
            graph[edge[1]].push_back(edge[0]) ;
        }
        vector<int>vis(n,0) ;
        dfs(0,graph,vis,labels,num) ;
        vector<int>ans ;
        for(int i = 0 ; i < n ;i++)
        {
            ans.push_back(num[i][labels[i]-'a']) ;
        }
        return ans ;
    }
};