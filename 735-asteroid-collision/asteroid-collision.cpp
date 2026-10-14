class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ;
        for(auto it : asteroids)
        {
            int flag = 1 ;
            if(it>0)st.push(it);
            else{
            while(!st.empty() && st.top()*it<0)
            {
                if(abs(it)==abs(st.top()))
                {
                    st.pop() ;
                    flag = 0 ;
                    break;
                }
                else if(abs(it)>abs(st.top()))
                {
                    st.pop() ;
                }
                else{
                    flag=0;
                    break ;
                }
            }
            if(flag)st.push(it) ;
            }
        }
        vector<int> ans ;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop() ;
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};