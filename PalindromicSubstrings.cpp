class Solution {
public:
    int countSubstrings(string s) {
        int maxs = 0;
        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
            maxs += count;
            count = 0;
            l = i, r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
                count++;
            }
            maxs += count;
        }
       
        return maxs;
    }
};
