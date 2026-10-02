class Solution {
public:
void func(int n , int ab , string &temp ,  vector<string>&ans)
{
    if(temp.size()==2*n){
        if(ab==0)
        {
            ans.push_back(temp) ;
        }
        return ;
    }
    if(ab<n)
    {
        temp.push_back('(') ;
        func(n,ab+1,temp,ans) ;
        temp.pop_back() ;
    }
    if(ab>0)
    {
        temp.push_back(')') ;
        func(n,ab-1,temp,ans) ;
        temp.pop_back() ;
    }
    return ;
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "" ;
         func(n,0,temp,ans) ;
         return ans ;
    }
};