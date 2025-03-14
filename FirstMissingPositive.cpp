class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (int i = 1; i < INT_MAX; i++)
            if (m.find(i) == m.end())
                return i;
        return INT_MAX;
    }
};
