class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> m;
        for (int i = 0; i < position.size(); i++) m.push_back({position[i], speed[i]});
        sort(m.rbegin(), m.rend());
        vector<double> s;
        for (int i = 0; i < position.size(); i++) {
            double t = (double)(target-m[i].first)/m[i].second;
            s.push_back(t);
            if (s.size() >= 2 && t <= s[s.size()-2])
                s.pop_back();
        }
        return s.size();
    }
};
