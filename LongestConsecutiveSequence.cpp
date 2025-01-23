class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        map<int, int> m;
        int mins = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mins = min(mins, nums[i]);
            m[nums[i]]++;
        }
        int prev = mins;
        int mcount = 0;
        int count = 0;
        for (const auto b: m) {
            if (b.first-1 == prev)
                count++;
            else {
                mcount = max(mcount, count);
                count = 0;
            }
            prev = b.first;
        }
        mcount = max(mcount, count);
        return mcount+1;
    }
};
