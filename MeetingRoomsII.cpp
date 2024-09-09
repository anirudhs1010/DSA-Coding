class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto u: intervals) {
            m[u[0]]++;
            m[u[1]]--;
        }
        int res = 0, curr = 0;
        for (auto h: m) {
            res = max(res, curr+=h.second);
        }
        return res;
    }
};
