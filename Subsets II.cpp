class Solution {
public:
    vector<int> a;
    vector<vector<int>> ans;
    void dfs(int k, vector<int> nums) {
        if (k >= nums.size()) {
            ans.push_back(a);
            return;
        }
        a.push_back(nums[k]);
        dfs(k+1, nums);
        a.pop_back();
        dfs(k+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> g;
        dfs(0, nums);
        for (vector<int> m : ans) {
            sort(m.begin(), m.end());
            g.insert(m);
        }
        for (const auto a: g)
            res.push_back(a);
        return res;
    }
};
