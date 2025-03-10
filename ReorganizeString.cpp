class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        priority_queue<pair<int, char>> q;
        for (const auto b : m) {
            q.push({b.second, b.first});
        }
        string res = "";
        while (q.size() > 1) {
            pair<int, char> f;
            pair<int, char> s;
            f = q.top();
            q.pop();
            res += f.second;
            f.first--;
            s = q.top();
            q.pop();
            res += s.second;
            s.first--;
            if (s.first != 0)
                q.push(s);
            if (f.first != 0)
                q.push(f);
        }
        if (q.size() == 1) { //if remaining character in odd case
            pair<int, char> f;
            f = q.top();
            q.pop();
            res += f.second;
            if (f.first > 1)
                return "";
            return res;
        }
        else
            return res;

        
    }
};
