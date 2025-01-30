class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN;
        int maxP = 1;
        for (int i = 0; i < nums.size(); i++) {
            maxP *= nums[i];
            a = max(a, maxP);
            if (maxP == 0)
                maxP = 1;
        }
        int maxN = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            maxN *= nums[i];
            a = max(a, maxN);
            if (maxP == 0)
                maxP = 1;
        }
        return max(a, b);
    }
};
