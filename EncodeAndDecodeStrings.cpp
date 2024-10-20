
class Codec {
public:
string encode(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            string u = strs[i];
            ans += "#";
            ans += to_string(u.size());
            ans += "#";
            ans += u;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            i++;
            string num = "";
            while (isdigit(s[i])) {
                num += s[i];
                i++;
            }
            int n = stoi(num);
            string ans = s.substr(i+1, n);
            res.push_back(ans);
            i+=n+1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
