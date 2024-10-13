class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        map<int, int> m;
        sort(intervals.begin(), intervals.end(), [] 
        (const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int count = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];
            if (prev[1] > curr[0]) {
                count++;
                if (prev[1] > curr[1])
                    prev = curr;
            }
            else
                prev = curr;
        }
        return count;
    }
};
