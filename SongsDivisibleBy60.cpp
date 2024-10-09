class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> ans;
        for (int i = 2; i <= 1000; i++) {
            if (i%60 == 0)
                ans.push_back(i);
        }
        map<int, int> m;
        for (int i = 0; i < time.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                if (m.count(ans[j] - time[i]) > 0) {
                    count+=m[ans[j] - time[i]];
                }
            }
            m[time[i]]++;
 
        }
        return count;
    }
};
