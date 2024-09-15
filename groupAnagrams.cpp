class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) != m.end()) {
                vector<string> a = m[s];
                a.push_back(strs[i]);
                m[s] = a;
            }
            else {
                m[s] = {strs[i]};
            }
        }
        vector<vector<string>> res;
        for (const auto b: m) {
            res.push_back(b.second);
        }
        return res;
    }
};
