class Solution {
public:
void func(int ind , int ab , int remove , string&s , string&temp , set<string>&ans)
{
    int n = s.size() ;
    if(ind==n && ab==0 && remove==0)
    {
        ans.insert(temp) ;
        return ;
    }
    if(ind==n || ab<0)
    {
        return ;
    }

    if(s[ind]!='(' && s[ind]!=')') 
    {
         temp.push_back(s[ind]) ;
        func(ind+1,ab,remove,s,temp,ans) ;
         temp.pop_back() ;
         return;
    }

    if(s[ind]=='(')
    {
            if(remove>0)
        func(ind+1,ab,remove-1,s,temp,ans) ;
         temp.push_back(s[ind]) ;
       func(ind+1,ab+1,remove,s,temp,ans) ;  
       temp.pop_back() ;
    } 
    if(s[ind]==')')
    {
            if(remove>0)
        func(ind+1,ab,remove-1,s,temp,ans) ;
          temp.push_back(s[ind]) ;
       func(ind+1,ab-1,remove,s,temp,ans) ;  
       temp.pop_back() ;
    
    }
 
        {
            
        }
    
    return  ;
}
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size() ;
        int temp = 0 ;
        int flag = 0 ;
        for(auto it : s)
        {
            if(it!='(' && it!=')') continue ;
            if(it=='(')flag++ ;
            else{
                if(flag>0)
                flag-- ;
                else{
                    temp++;
                }
            }
        }
        temp+=flag ;
        set<string>ans ;
        string st = ""; 
        func(0,0,temp,s,st,ans) ;
        vector<string>valid ;
        for(auto &it : ans)
        {
            valid.push_back(it) ;
        }
        if(valid.size()==0)return{""} ;
        return valid ;
    }
};