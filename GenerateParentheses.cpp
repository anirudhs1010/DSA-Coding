//review this
class Solution {
public:
    vector<string> ans;
    stack<char> s;
    string y = "";
    void backtrack(int l, int r, int n) {
        if (l == r && r == n) {
            ans.push_back(y);
            return;
        }
        if (l < n) {
            y.push_back('(');
            backtrack(l+1, r, n);
            y.pop_back();
        }
        if (r < l) {
            y.push_back(')');
            backtrack(l, r+1, n);
            y.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string h = "";
        backtrack(0, 0, n);
        return ans;
    }
};
