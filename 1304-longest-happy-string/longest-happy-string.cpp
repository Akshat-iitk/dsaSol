class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>>pq ;
        if(a) pq.push({a,0});
        if(b) pq.push({b,1});
        if(c) pq.push({c,2});

string ans="" ;
vector<pair<int,int>>temp ;
        while(!pq.empty())
        {
            auto curr = pq.top() ;
            pq.pop() ;
            int n = ans.size() ;
            if(ans.size()==0 || (ans[n-1]-'a')!=curr.second)
            {
                ans.push_back(curr.second+'a') ;
                curr.first-- ;
                if(curr.first) 
                pq.push({curr.first,curr.second}) ;
                for(auto it : temp)
                {
                    pq.push(it) ;
                }
                temp.clear() ;   
            }
            else{
                ans.push_back(curr.second+'a') ;
                curr.first-- ;
                if(curr.first)
                temp.push_back({curr.first,curr.second}) ;
            }
        }
        return  ans ;
    }
};