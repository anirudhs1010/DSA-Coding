class Solution {
public:
    vector<vector<int>> memo;
    int dfs(string a, string b, int i, int j) {
        if (i == a.size() || j == b.size())
            return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (a[i] == b[j]) {
            memo[i][j] = 1+dfs(a, b, i+1, j+1);   
        }
        else
            memo[i][j] = max(dfs(a, b, i+1, j), dfs(a, b, i, j+1));
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }
};
