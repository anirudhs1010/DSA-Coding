class Solution {
public:
    string removeDuplicates(string s, int k) {
        int count = 0;
        string ans = "";
        stack<pair<char, int>> st; 
        for (int i = s.size()-1; i >= 0; i--) {
            if (!st.empty() && st.top().first == s[i]) {
                st.top().second++;
                if (st.top().second == k)
                    st.pop();
            }
            else
                st.push({s[i], 1});
        }
        while (!st.empty()) {
            char y = st.top().first;
            while (st.top().second--) ans.push_back(y);
            st.pop();
        }
        
        return ans;
    }
};
