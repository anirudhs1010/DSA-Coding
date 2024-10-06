class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        int maxs = 0;
        //sliding widnow
        int l = 0, r = 0; 
        int mcount = 0;
        while (r < s.size()) {
            m[s[r]]++;
            //find max char count in the window
            for (const auto b : m) {
                if (b.second > mcount) {
                    mcount = b.second;
                }
            }
            // if we cannot replace it with k characters and maximize, l++
            while ((r-l + 1) - mcount > k) {
                m[s[l]]--;
                l++;
            }
            maxs = max(maxs, r-l+1);
            r++;
            
        }
        
        return maxs;
    }
};
