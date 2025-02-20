class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m; //hashmap to store all the data
        for (int i = 0; i < cpdomains.size(); i++) {
            string s = cpdomains[i];
            string num = "";

            int h = s.find(" "); //split by string
            string web = s.substr(h+1);
            int n = stoi(s.substr(0, h));
            m[web] += n;
            for (int j = 0; j < web.size(); j++) { //loop through and detect any periods
                if (web[j] == '.') {// if we find a period we have a new website to update
                    m[web.substr(j+1)] += n; 
                }
            }
        }
        vector<string> v;
       // put the fries in the bag lil bro
        for (const auto b : m) {
            string a = to_string(b.second) + " " + b.first;
            v.push_back(a);
        }
        return v;
    }
};
