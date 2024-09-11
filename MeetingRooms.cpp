//memorize custom comparators
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];
            if (prev[1] > curr[0])
                return false;
            prev = intervals[i];            
        }
        return true;
    }
};
