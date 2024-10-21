class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for (int i = 0; i < points.size()-1; i++) {
            vector<int> a = points[i];
            vector<int> b = points[i+1];
            total += abs(abs(a[0]-b[0]) - abs(a[1]-b[1]));
            total += min(abs(b[0] - a[0]), abs(b[1] - a[1]));
        }
        return total;
    }
};
