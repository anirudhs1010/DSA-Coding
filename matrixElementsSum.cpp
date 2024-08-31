//https://app.codesignal.com/arcade/intro/level-2/xskq4ZxLyqQMCLshr
int solution(vector<vector<int>> matrix) {       
    int n = size(matrix);
    int m = size(matrix[0]);
    int sum = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] == 0) break;
            sum += matrix[j][i];
        }
    }
    
    return sum;
}
