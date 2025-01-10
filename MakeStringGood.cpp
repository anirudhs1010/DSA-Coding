class Solution {
public:
    string makeGood(string s) {
        stack<char> p;
        for (int i = 0; i < s.size(); i++) {
            if (!p.empty() && isupper(s[i]) && p.top() == tolower(s[i]))
                p.pop();
            else if (!p.empty() && isupper(p.top()) && tolower(p.top()) == s[i])
                p.pop();
            else
                p.push(s[i]);
        }
        string ans = "";
        while (!p.empty()) {
            ans += p.top();
            p.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
