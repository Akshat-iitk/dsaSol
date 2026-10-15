class Solution {
public:
    string decodeString(string s) {
        stack<char> st ;
        for(auto it : s)
        {
            if(it!=']')
            {
                st.push(it) ;
            }
            else{
                string temp ;
                while(st.top()!='[')
                {
                    temp.push_back(st.top()) ;
                    st.pop() ;
                }
                st.pop() ;
                reverse(temp.begin(),temp.end()) ;
                string numstr = "" ;
                while(!st.empty() && st.top()>='0' && st.top()<='9')
                {
                    numstr.push_back(st.top()) ;
                    st.pop() ;
                }
                reverse(numstr.begin(),numstr.end()) ;
                int num = stoi(numstr) ;
                cout<<num<<endl ;
                string final = "" ;
                while(num--)
                {
                    final+=temp ;
                }
                cout<<final<<endl ;
                for(auto it : final)
                {
                    st.push(it) ;
                }
            }
        }
        string ans = "" ;
        while(!st.empty())
        {
            ans.push_back(st.top()) ;
            st.pop() ;
         }
         reverse(ans.begin(),ans.end()) ;
         return ans ;
    }
};