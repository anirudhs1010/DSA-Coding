//not quite there for backtracking

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> candidates, vector<int> b, int target, int index) {
        if (target == 0) {
            ans.push_back(b);
            return;
        }
        if (index >= candidates.size() || target < 0) {
            return;
        }
        b.push_back(candidates[index]);
        dfs(candidates, b, target-candidates[index], index);
        b.pop_back();
        dfs(candidates, b, target, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> t;
        dfs(candidates, t, target, 0);
        return ans;
    }
};
