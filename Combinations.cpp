class Solution {
public:
    vector<vector<int>> ans;
    
    vector<int> v;
    int s = 0;
    void backtrack(vector<int>& a, int i) {
        if (a.size() == s) {
            ans.push_back(a);
            return;
        }
        if (i >= v.size())
            return;
        a.push_back(v[i]);
        backtrack(a, i+1);
        a.pop_back();
        backtrack(a, i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        s = k;
        vector<int> g;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        backtrack(g, 0);
        return ans;
    }
};
