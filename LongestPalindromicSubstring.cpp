class Solution {
public:
   
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s;
        string ans = "";
        int maxs = 0;
        for (int i = 0; i < s.size(); i++) {
            //even
            int l = i, r = i;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                if ((r - l + 1) > maxs) {
                    maxs = r - l + 1;
                    ans = s.substr(l, maxs);
                }
                l--;
                r++;
            }
            //odd
            l = i;
            r = i+1;
            while (l >= 0 && r <= s.size()-1 && s[l] == s[r]) {
                if ((r - l + 1) > maxs) {
                    maxs = r - l + 1;
                    ans = s.substr(l, maxs);
                }
                l--;
                r++;
            }
            
        }
        return ans;
    }
};
