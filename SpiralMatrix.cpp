class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; // Handle empty matrix
        
        int l = 0, r = matrix[0].size(); // `r` should be the number of columns
        int t = 0, b = matrix.size();    // `b` should be the number of rows
        vector<int> ans;
        
        while (l < r && t < b) {
            // Traverse from left to right
            for (int i = l; i < r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;
            
            // Traverse from top to bottom
            for (int i = t; i < b; i++) {
                ans.push_back(matrix[i][r-1]);
            }
            r--;

            if (!(t < b) || !(l < r))
                break;
            // Traverse from right to left
            for (int i = r-1; i >= l; i--) {
                ans.push_back(matrix[b-1][i]);
            }
            b--;
            
            // Traverse from bottom to top
            for (int i = b-1; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++;
            
        }
        
        return ans;
    }
};
