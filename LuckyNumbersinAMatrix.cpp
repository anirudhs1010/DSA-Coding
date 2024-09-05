class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            int m= INT_MAX;
            int mx = 0;
            int min_j = 0;
            int min_i = 0;
            int max_i = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (m > matrix[i][j]) {
                    m = matrix[i][j];
                    min_j = j;
                    min_i = i;
                }
            }
            for (int k = 0; k < matrix.size(); k++) {
                if (mx < matrix[k][min_j]) {
                    mx = matrix[k][min_j];
                    max_i = k;
                }
            }
            if (max_i == min_i)
                ans.push_back(matrix[min_i][min_j]);
        }
        return ans;
    }
};
