class Solution {
public:
    vector<vector<int>> ans;
    vector<int> s;
    void dfs(int index, vector<int> n) {
        if (index >= n.size()) {
            ans.push_back(s);
            return;
        }
        s.push_back(n[index]);
        dfs(index+1, n);
        s.pop_back();
        dfs(index+1, n);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        dfs(0, nums);

        return ans;
    }
};
