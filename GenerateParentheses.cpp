class Solution {
public:

    vector<string> v;
    int sz = 0;
    void backtrack(int open, int close, string s) {
        if (s.size() == 2*sz) {
            v.push_back(s);
            return;
        }
        if (open < sz) {
            backtrack(open+1, close, s + "(");
        }
        if (close < open) {
            backtrack(open, close+1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        sz = n;
        backtrack(1, 0, "(");
        return v;
    }
};
