class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        string b = strs[0];
        sort(b.begin(), b.end());
        m[b].push_back(strs[0]);
        for (int i = 1; i < strs.size(); i++) {
            string a = strs[i];
            sort(a.begin(), a.end());
            m[a].push_back(strs[i]);
            //notice you don't need to actually search the map (use it for sorting)
        }
        vector<vector<string>> v;
        for (const auto b : m) {
            v.push_back(b.second);
        }
        return v;
    }
};
