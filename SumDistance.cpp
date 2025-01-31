class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> a;
        for (int i = 0; i < nums.size(); i++)
            a.push_back(nums[i]);
            
        for (int i = 0; i < nums.size(); i++) {
            if (s[i] == 'L') {
                a[i] -= d;
            }
            if (s[i] == 'R') {
                a[i] += d;
            }
        }
        
        sort(a.begin(), a.end());
        long long sum = a[0];   // Changed to long long
        long long rsum = 0;  
        const int MOD = 1e9 + 7;
        for (int i = 1; i < a.size(); i++) {
            (rsum = rsum + (a[i] * i) - sum) %= MOD;
            (sum = (sum + a[i])) %= MOD;
        }
        
        return rsum;
    }
};
