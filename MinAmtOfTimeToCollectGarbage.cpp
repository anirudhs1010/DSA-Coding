class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        map<char, int> m;
        int time = 0;
        //why did we ever need 3
        vector<int> psumsT(garbage.size()+1, 0);
        for (int i = 1; i < travel.size()+1; i++) {
            psumsT[i] = psumsT[i-1] + travel[i-1];
        }
        int lastP = 0, lastM = 0, lastG = 0;
        for (int i = 0; i < garbage.size(); i++) {
            string y = garbage[i];
            m.clear();
            for (int j = 0; j < garbage[i].size(); j++) {
                m[y[j]]++;
            }
            time += y.size();
            if (m.find('G') != m.end() && i != 0)
                lastG = i;
            if (m.find('M') != m.end() && i != 0)
                lastM = i;
            if (m.find('P') != m.end() && i != 0)
                lastP = i;
        }
        return time + psumsT[lastG] + psumsT[lastM] + psumsT[lastP];
    }
};
