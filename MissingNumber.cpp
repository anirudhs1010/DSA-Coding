class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
            r += nums[i];
        return sum - r;  
    }
};
