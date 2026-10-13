class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size() ;
        vector<int> arr(26,0) ;
        for(auto it : s)
        {
            arr[it-'a']++; 
        }
        priority_queue<pair<int,int>>pq ;
        for(int i = 0 ; i < 26 ;i++)
        {
            if(arr[i]) 
            pq.push({arr[i],i}) ;
        }
        string ans = "" ;
        while(!pq.empty())
        {
            vector<pair<int,int>>temp ;
            for(int i = 0 ; i < 2 ; i++)
            {
                    if(pq.empty() && temp.size()!=0)return "" ;
                if(!pq.empty())
                {
                    auto curr = pq.top() ;
                    pq.pop() ;
                    ans.push_back(char('a'+curr.second)) ;
                    curr.first--;
                    if(curr.first) temp.push_back(curr) ;
                }
            }
            for(auto &it : temp)
            {
                pq.push(it) ;
            }
        }
        return ans ;
    }
};