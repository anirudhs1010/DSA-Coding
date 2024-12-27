class Solution {
public:
    int ans = 0;
    void backtrack(int target, int i, vector<int> a) {
        if (i == a.size()) {
            if (target == 0)
                ans++;
            return;
        }
        backtrack(target-a[i], i+1, a);
        backtrack(target+a[i], i+1, a);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(target, 0, nums);
        return ans;
    }
};
