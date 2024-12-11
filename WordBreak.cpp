class Solution {
public:
    map<int, bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        m[s.size()] = true;
        return dfs(s, wordDict, 0);
    }
private:
    bool dfs(const string& s, const vector<string>& wordDict, int i) {
        if (m.find(i) != m.end())
            return m[i];
        if (i == s.length()) {
            return true;
        }

        for (const string& w : wordDict) {
            if (i + w.length() <= s.length() && 
                s.substr(i, w.length()) == w) {
                m[i] = true;
                return dfs(s, wordDict, i + w.length());
            }
        }
        m[i] = false;
        return false;
    }
};
