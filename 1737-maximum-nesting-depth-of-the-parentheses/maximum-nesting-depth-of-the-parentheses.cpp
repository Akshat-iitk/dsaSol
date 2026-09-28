class Solution {
public:
    int maxDepth(string s) {
        stack<char>st ;
        int ans = 0 ;
        for(auto it : s)
        {
            if(it == '(')
            {
                st.push(it) ;
                int sz = st.size();
                ans = max(ans,sz) ;
            }
            else if(it==')')
            {
                st.pop() ;
            }
        }
        return ans; 
    }
};