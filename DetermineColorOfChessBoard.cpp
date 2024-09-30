class Solution {
public:
    bool squareIsWhite(string coordinates) {
        string od = "aceg";
        string ev = "bdfh";
        map<char, int> m;
        map<char, int> a;
        for (int i = 0; i < od.size(); i++) {
            m[od[i]]++;
            a[ev[i]]++;
        }
        if (m.find(coordinates[0]) != m.end()) {
            if (coordinates[1] %2 == 0)
                return true;
            else
                return false;
        }
        if (coordinates[1]%2 == 0)
            return false;
        return true;
    }
};
