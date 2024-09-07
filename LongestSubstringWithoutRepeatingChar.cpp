class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> a;
        int mx = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            while (a.find(s[r]) != a.end()) {
                a.erase(s[l]);
                l++;
            }
            
            a.insert(s[r]);
            mx = max((r-l)+1, mx);
            r++;
        }
 
        return mx;
    }
};
