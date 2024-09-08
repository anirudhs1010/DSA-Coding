class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[0].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //swap columns into middle
         for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size()/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[0].size()-j-1];
                matrix[i][matrix[0].size()-j-1] = temp;
            }
        }

        

      
    }
};
