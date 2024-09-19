class Solution {
public:
    bool isValid(string s) {
        stack<char> y;
        int counter = 0, count= 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                counter++;
                y.push(s[i]);
            }
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                count++;
            if (y.size() != 0 && s[i] == ')' && y.top() == '(')
                y.pop();
            if (y.size() != 0 && s[i] == ']' && y.top() == '[')
                y.pop();
            if (y.size() != 0 && s[i] == '}' && y.top() == '{')
                y.pop();
            
        }
        return y.size()==0 && counter == count;
        
    }
};
