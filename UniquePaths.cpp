class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        //approach is to sum from left and up squares to bottom right
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
         
            }
        }
        return dp[m-1][n-1];
    }
};
