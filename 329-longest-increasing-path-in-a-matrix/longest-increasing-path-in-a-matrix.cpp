class Solution {
public:
static const int N = 2e2+5 ;
int dp[N][N] ;
    bool isvalid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    vector<int> movex = {-1, 1, 0, 0};
    vector<int> movey = {0, 0, 1, -1};
    int func(int i, int j, vector<vector<int>>& matrix) {
        int ans = 1;
         int n = matrix.size();
        int m = matrix[0].size();
        if(dp[i][j]!=-1)return dp[i][j] ;
        for (int k = 0; k <= 3; k++) {
            int newx = i + movex[k];
            int newy = j + movey[k];
            if (isvalid(newx, newy, n, m) &&
                matrix[newx][newy] > matrix[i][j]) {
                ans = max(ans, 1 + func(newx, newy,matrix));
            }
        }
        return dp[i][j] =  ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp,-1,sizeof(dp)) ;
        int dis = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dis = max(dis,func(i,j,matrix)) ;
            }
        }
        return dis ;
    }
};