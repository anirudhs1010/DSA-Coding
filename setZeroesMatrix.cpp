class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix[0].size(), false);
        vector<bool> col(matrix.size(), false);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[j] = true;
                    col[i] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row[j] | col[i]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
