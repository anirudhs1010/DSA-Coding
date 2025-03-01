class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        int b = 0, a= 0, l = 0, o = 0, n = 0;
        for (int i = 0; i < text.size(); i++) {
            m[text[i]]++;
            if (text[i] == 'b')
                b++;
            if (text[i] == 'a')
                a++;
            if (text[i] == 'l')
                l++;
            if (text[i] == 'o')
                o++;
            if (text[i] == 'n')
                n++;
        }
        return min(b, min(min(l/2, o/2), min(a, n)));
        
    }
};
