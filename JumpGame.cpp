class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums[0];
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] + i >= target)
                target = i;
            
        }
        return target == 0;
        
    }
};
