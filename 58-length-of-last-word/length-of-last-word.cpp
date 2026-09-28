class Solution {
public:
//hello
    int lengthOfLastWord(string s) {
        string temp ;
        string last ;
        for(auto it : s)
        {
            if(it == ' ')
            {
                if(temp.size()!=0)
                last = temp ;
                temp = "" ;
            }
            else
            temp.push_back(it) ;
        }
        if(temp.size()==0)return last.size() ;
        return temp.size() ;
    }
};