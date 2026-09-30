class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<pair<int,int>>st ;
        vector<int> ans ;
        for(auto it : seq)
        {
            if(st.empty())
            {
                st.push({it,0}) ;
                ans.push_back(0) ;
            }
            else{
                auto [ele,depth] = st.top() ;
                if(it=='(')
                {
                    if((depth+1)%2==0) ans.push_back(0);
                    else ans.push_back(1) ;
                    st.push({it,depth+1}) ;
                }
                else{
                    if((depth)%2==0) ans.push_back(0);
                    else ans.push_back(1) ;
                st.pop() ;
                }   
            }
        }
            return ans ;
    }
};