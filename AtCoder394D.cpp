#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> g;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '<' || s[i] == '[')
            g.push(s[i]);
        else if (!g.empty()) {
            if (g.top() == '(' && s[i] == ')')
                g.pop();
            else if (g.top() == '[' && s[i] == ']')
                g.pop();
            else if (g.top() == '<' && s[i] == '>')
                g.pop();
            else
                return false;
        }
        else
            return false;
    }
    return g.empty();
}

int main()
{
    string s;
    cin >> s;
    if (isValid(s))
        cout << "Yes" <<endl;
    else
        cout<<"No";
    return 0;
}
