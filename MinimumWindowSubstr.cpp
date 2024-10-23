class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for (char c : t)
            m[c]++;
        int l = 0, r = 0;
        map<char, int> a;
        int ans = INT_MAX;
        int count = 0;
        int fl = 0, fr = 0;
        while (r < s.size()) {
            char x = s[r];
            if (m.find(x) != m.end()) { //we are in a valid window
                a[x]++;
                if (a[x] == m[x])
                    count++;
            }
            while (count == m.size()) {
                if (ans > r-l+1) {
                    fr = r - l + 1;
                    fl = l;
                    ans = fr;
                }
                if (m.find(s[l]) != m.end()) {
                    a[s[l]]--;
                    if (a[s[l]] < m[s[l]])
                        count--;
                }
                l++;
            }
            r++;
        }
        return s.substr(fl, fr);
    }
};
