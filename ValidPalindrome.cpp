class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for (int i = 0; i < s.size(); i++)
            if (isalpha(s[i]) || isdigit(s[i])) //attention to detail here
                a.push_back(s[i]);
        int i = 0, j = a.size()-1;
        for (int i = 0; i < a.size()/2; i++) {//don't do = a.size()/2, some mem error
            if (tolower(a[i]) != tolower(a[j])) 
                return false;
            j--;
        }
        return true;
    }
};
