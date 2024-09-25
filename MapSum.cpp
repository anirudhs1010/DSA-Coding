class MapSum {
public:
    map<string, int> m;
    MapSum() {
        m["0"] = {};
    }
    
    void insert(string key, int val) {
        m[key] =val;
    }
    
    int sum(string prefix) {
        int sums = 0;
        for (const auto b: m) {
            string s = b.first;
            if (s.substr(0, prefix.size()) == prefix)
                sums += b.second;
        }
        return sums;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
