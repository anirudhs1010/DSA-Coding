class Solution {
public:
    vector<vector<int>> P;
    vector<int> v;
    void backtrack(int s, vector<int> a) {
        if (s == a.size()) {
            P.push_back(v);
            return;
        }
        v.push_back(a[s]);
        backtrack(s+1, a);
        v.pop_back();
        backtrack(s+1, a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return P;
    }
};
