class Solution {
public:
    string a;
    unordered_map<int, int> dp;
    int dfs(int i) {
        if (dp.count(i))
            return dp[i];
        if (a[i] == '0') {
            return 0;
        }
        int res = dfs(i+1);
        if (i +1 < a.size() && (a[i] == '1' || 
               (a[i] == '2' && a[i + 1] < '7')))
            res += dfs(i+2);
        dp[i] = res;
        return res;

    }
    int numDecodings(string s) {
        dp[s.size()] = 1;
        a = s;
        return dfs(0);
    }
};
