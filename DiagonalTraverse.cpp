class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int counter = 0;
        vector<int> res;
        while (i < mat.size() && j < mat[0].size()) {
            int a = i, b = j;
            vector<int> ans;
            while (a < mat.size() && b >= 0) {
                ans.push_back(mat[a][b]);
                a++;
                b--;
            }
            if (counter %2 == 0) {
                reverse(ans.begin(), ans.end());
            }
            for (int x = 0; x < ans.size(); x++)
                res.push_back(ans[x]);
            if (j < mat[0].size()-1)
                j++;
            else
                i++;
            counter++;
        }
        return res;
    }
};
