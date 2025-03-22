class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> v = intervals[i];
            m[v[0]]++;
            m[v[1]]--;
        }
        int curr = 0, tot = 0;
        for (const auto b:m) {
            curr += b.second;
            tot = max(tot, curr);
        }
        return tot;
    }
};
