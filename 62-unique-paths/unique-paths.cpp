class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,0)) ;
            vector<int> prev(m,0) ;
            vector<int> curr(m,0) ;

        // prev[0] = 1 ;
        curr[0] = 1 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                // if(i==0 && j==0) curr[j] = 1 ;
                // else{                
                if(i==0 && j==0)continue ;
               int move = 0 ;
                if(i>0) move+= prev[j] ;
                if(j>0) move +=curr[j-1] ;
                curr[j] = move ;
                // }
                
            }
            prev = curr ;
        }
        return curr[m-1] ;
    }
};