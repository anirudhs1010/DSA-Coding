//bad one imo
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (prev[1] >= interval[0]) {
                prev[1] = max(prev[1], interval[1]);
                
            }
            else {
                ans.push_back(prev);
                prev = intervals[i];
                
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
