class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0 ;
        int temp = 0 ;
        for(auto it : s)
        {
            if(it=='(')temp++ ;
            if(it==')')
            {
                if(temp==0)ans++;
                else {
                    temp-- ;
                }
            }
        }
        ans+=temp ;
        return ans ;
    }
};