class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> st ;
            vector<pair<int,int>>arr;
            int n = speed.size() ;
            for(int i = 0 ; i<n ; i++)
            {
                arr.push_back({position[i],speed[i]}) ;
            }
            sort(arr.rbegin(),arr.rend()) ;
            for(auto it : arr)
            {
                    int flag = 1 ;
                while(!st.empty())
                {
                    auto curr = st.top() ;
                    if(it.second>curr.second)
                    {
                        double forw = (double)((target-curr.first)/(curr.second*1.0)) ;
                        double back = (double)((curr.first-it.first)/((it.second-curr.second)*1.0)) ;
                        if(back<=forw) 
                        {
                            flag = 0;
                        }
                    }
                        break ;
                    
                }
                if(flag)
                st.push({it.first,it.second}) ;
            }
            return (st.size()) ;
          
    }
};