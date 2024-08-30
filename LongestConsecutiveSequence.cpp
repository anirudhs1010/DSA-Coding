class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int mx = 1;
        int prev = INT_MAX;
        int cs = 1;
        for (const auto a: m) {
            if (cs > mx)
                mx = cs;
            if (prev != INT_MAX && prev + 1 == a.first) {
                cs++;
            }
            else
                cs = 1;
            prev = a.first;
        }
        if (cs > mx)
            mx = cs;
        return mx;
    }
};
