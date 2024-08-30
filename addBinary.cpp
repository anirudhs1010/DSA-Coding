class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        string ans = "";
        if (a.size() >= b.size()) {
            int j = b.size()-1;
            for (int i = a.size()-1; i >= 0; i--) {
                if (carry && j >= 0) {
                    if (a[i] == '0' && b[j] == '0') {
                        ans = '1' + ans;
                        carry = false;
                    }
                    else if (a[i] == '1' && b[j] == '1')
                        ans = '1' + ans;
                    else
                        ans = '0' + ans;
                }
                else if (carry) {
                    if (a[i] == '0') {
                        ans = '1' + ans;
                        carry = false;
                    }
                    else
                        ans = '0' + ans;
                }
                else if (j >= 0 && a[i] == b[j] && a[i] == '1') {
                    carry = true;
                    ans = '0' + ans;
                }
                else if (j >= 0 && a[i] == b[j]) {
                    ans = '0' + ans;
                }
                else if (j >= 0 && a[i] != b[j])
                    ans = '1' + ans;
                else if (j < 0)
                    ans = a[i] + ans;
                j--;
            }
        }
        else {
            string temp = a;
            a = b;
            b = temp;
            int j = b.size()-1;
            for (int i = a.size()-1; i >= 0; i--) {
                if (carry && j >= 0) {
                    if (a[i] == '0' && b[j] == '0') {
                        ans = '1' + ans;
                        carry = false;
                    }
                    else if (a[i] == '1' && b[j] == '1')
                        ans = '1' + ans;
                    else
                        ans = '0' + ans;
                }
                else if (carry) {
                    if (a[i] == '0') {
                        ans = '1' + ans;
                        carry = false;
                    }
                    else
                        ans = '0' + ans;
                }
                else if (j >= 0 && a[i] == b[j] && a[i] == '1') {
                    carry = true;
                    ans = '0' + ans;
                }
                else if (j >= 0 && a[i] == b[j]) {
                    ans = '0' + ans;
                }
                else if (j >= 0 && a[i] != b[j])
                    ans = '1' + ans;
                else if (j < 0)
                    ans = a[i] + ans;
                j--;
            }
        }
        if (carry)
            return '1' + ans;
        return ans;
        
        
    }
};
