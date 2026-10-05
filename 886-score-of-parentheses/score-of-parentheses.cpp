class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char>st ;
        int ans = 0 ;
        int flag = 0 ;
        for(auto it : s)
        {
           if(it=='(')
           {
            flag = 1 ;
            st.push(it) ;
           }
           if(it==')')
           {
            if(flag == 1)
            {
                int temp = st.size() ;
                ans+=(1<<(temp-1)) ;
                flag = 0 ;
            }
            st.pop() ;
           }
        }
            return ans ;
    }
};