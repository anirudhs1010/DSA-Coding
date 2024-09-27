class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        map<char, int> c;
        int ind = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            c[s[i]] = i;
        }
        for (const auto b: m) {
            if (b.second == 1)
                ind = min(ind, c[b.first]);
        }
        if (ind == INT_MAX)
            return -1;
        return ind;
    }
};
