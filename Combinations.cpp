class Solution {
public:
    vector<vector<int>> v;
    vector<int> ans;
    void backtrack(int n , int k, int index) {
        if (ans.size() == k) {
            v.push_back(ans);
            return;
        }
        for (int i = index; i <= n; i++) {
            ans.push_back(i);
            backtrack(n, k, i+1);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return v;
    }

};
