class NumMatrix {
public:
    vector<vector<int>> psums;

    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();

        psums.resize(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                psums[i][j] = matrix[i][j];
                if (i > 0) psums[i][j] += psums[i-1][j];
                if (j > 0) psums[i][j] += psums[i][j-1];
                if (i > 0 && j > 0) psums[i][j] -= psums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = psums[row2][col2];
        if (row1 > 0) total -= psums[row1-1][col2];
        if (col1 > 0) total -= psums[row2][col1-1];
        if (row1 > 0 && col1 > 0) total += psums[row1-1][col1-1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
