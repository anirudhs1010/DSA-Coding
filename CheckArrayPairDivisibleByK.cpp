class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> m;
        if (arr.size()%2 != 0)
            return false;
        //(b + (a % b)) % b
        for (int i = 0; i < arr.size(); i++) {
            m[(k + arr[i] % k)%k]++;
        } 
        if (m[0]%2 != 0)
            return false;
        for (const auto b : m) {
            if (b.first != 0 && b.second != m[k-b.first]) {
                return false;
            }
            
        }
        
        return true;
    }
};
