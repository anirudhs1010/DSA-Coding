class Solution {
public:
    int maxProduct(vector<int>& nums) {
       long long a = 1, n = INT_MIN;
       for (int i = 0; i < nums.size(); i++) {
            a *= nums[i];
            n = max(n, a);
            if (a == 0)
                a = 1;
       }
       a = 1;
       for (int i = nums.size()-1; i >= 0; i--) {
            a *= nums[i];
            n = max(n, a);
            if (a == 0)
                a = 1;
       } 
       return n;
           
    }
};
