class Solution {
public:
vector<string>result ;
bool func(string curr , unordered_map<string,priority_queue<string,vector<string>,greater<string>>>&mp,int n , vector<string>&ans)
{
        while(!mp[curr].empty())
        {
            string temp = mp[curr].top() ;
            mp[curr].pop() ;
            if(func(temp,mp,n,ans))return true ;
        }
    ans.push_back(curr) ;
     if(ans.size()==n+1)
    {
        result = ans ;
        return true ;
    }
    return false ;
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp ;
       int n = tickets.size() ;
       for(auto &ticket : tickets) 
       {
        mp[ticket[0]].push(ticket[1]) ;
       }
       vector<string>ans ;
       func("JFK",mp,n,ans) ;
       reverse(result.begin(),result.end()) ;
            return result ;
    }
};