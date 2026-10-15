class Solution {
public:
 bool isposs(int i , int j , vector<vector<char>> &board , char c)
 {
    for(int k = 0 ; k < 9 ; k++)
    {
        if(board[k][j]==c) return false ;
        if(board[i][k]==c) return false ; 
    }
    int rownum = (i/3)*3 ;
    int colnum = (j/3)*3 ;
    for(int i = rownum ; i < rownum+3 ; i++)
    {
        for(int j = colnum ; j<colnum+3 ; j++)
        {
            if(board[i][j]==c) return false ;
         }
    }
    return true ;
 }
 bool solve(vector<vector<char>> &board)
 {
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            if(board[i][j]=='.')
            {
                for(char c = '1' ; c <='9' ; c++)
                {
                    if(isposs(i,j,board,c)){
                        board[i][j] = c ;
                        if(solve(board))return true ;
                       else board[i][j] = '.' ;
                    }
                }
                return false ;
            }
        }
    }
    return true ;
 }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board) ;
    }
};