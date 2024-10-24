class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> a = intervals[i];
            if (newInterval[1] < a[0]) { //insert in here and slide
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++)
                    res.push_back(intervals[j]);
                return res;
            }
            else if (newInterval[0] > a[1]){
                res.push_back(a);
            }
            else {
                newInterval[0] = min(newInterval[0], a[0]);
                newInterval[1] = max(newInterval[1], a[1]);
            }
            
        }
        res.push_back(newInterval);
        
        return res;
    }
};
