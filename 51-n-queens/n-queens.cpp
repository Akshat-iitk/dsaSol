class Solution {
public:
bool isvalid(int row , int col , vector<string> &temp)
{
    int n = temp.size() ;
    for(int i = row ; i>= 0 ; i--)
    {
        if(temp[i][col]=='Q') return false ;
    }
    for(int i = row-1 , j = col-1 ; i>=0 && j>=0 ; i--,j--)
    {
         if(temp[i][j]=='Q') return false ;
    }
    for(int i = row-1 , j = col+1 ; i>=0 && j<n ; i-- , j++)
    {
         if(temp[i][j]=='Q') return false ;
    }
    return true ;
}
void func(int row ,  vector<string> &temp , vector<vector<string>> &ans)
{
    int n = temp.size() ;
    if(row==n)
    {
        ans.push_back(temp) ;
        return ;
    }
    for(int j = 0 ; j < n ; j++)
    {
        if(isvalid(row,j,temp))
        {
            temp[row][j] = 'Q' ;
            func(row+1,temp,ans) ;
            temp[row][j] = '.' ;
        }
    }
    return ;
}
    vector<vector<string>> solveNQueens(int n) {
        string flag(n,'.') ;
        vector<string> temp ;
        vector<vector<string>>ans ;
        for(int i = 0 ; i < n ;i++)
        {
            temp.push_back(flag) ;
        }
        func(0, temp , ans) ;
        return ans ;
    }
};