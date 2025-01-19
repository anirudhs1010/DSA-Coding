class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0, r = 0;
        unordered_set<int> b;
        int maxs = 0;
        while (r < s.size()) {
            
            while (b.find(s[r]) != b.end()) {
                b.erase(s[l]);
                l++;
                
            }
            b.insert(s[r]);
            r++;
            maxs = max(maxs, r-l);
        }
        return maxs;
    }
};
