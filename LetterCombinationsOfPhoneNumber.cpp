class Solution {
public:
    vector<string> ans;
    string b;
    void backtrack(map<char, vector<char>> m, int id, string v) {
        if (b.size() == v.size()) { 
            ans.push_back(v);
            return;
        }
        vector<char> a = m[b[id]];
        for (int i = 0; i < a.size(); i++) {
            v += a[i];
            backtrack(m, id+1, v);
            v.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return ans;
        map<char, vector<char>> m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        b = digits;
        backtrack(m, 0, "");
        return ans;
    }
};
