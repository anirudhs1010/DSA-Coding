class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int j = 0;
        map<char, int> m;
        map<char, int> a;
        for (int i = 0; i < ransomNote.size(); i++)
            a[ransomNote[i]]++;

        for (int i = 0; i < magazine.size(); i++)
            m[magazine[i]]++;
        
        for (const auto c : a) {
            if (m.find(c.first) == m.end() || m[c.first] < c.second)
                return false;
        }
        
        return true;
    }
};
