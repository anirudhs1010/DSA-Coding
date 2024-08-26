class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp.push_back(max(nums[i], dp[i-1]+nums[i]));
            mx = max(dp[i], mx);
        }
        mx = max(dp[dp.size()-1], mx);
        return mx;
        
    }

};
