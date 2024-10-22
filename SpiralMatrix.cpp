class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int t = 0, b = matrix.size();
        int l = 0, r = matrix[0].size();
        vector<int> res;
        while (l != r && t != b) { //make sure our bounds are never equal 
            for (int i = l; i < r; i++) { //first we do the first row left to right
                res.push_back(matrix[t][i]);
            }
            t++; //each time we update the top bound and shrink since we dont need to consider that row anymore
            for (int i = t; i < b; i++) { //then we crawl along the last column down
                res.push_back(matrix[i][r-1]);
            }
            r--; //each time we update our right as we dont need to consider that column anymore.
            if (!(l < r) || !(t < b)) //we break in the middle if the conditions are violated i.e. it may not end before # operations divisible by 4.
                break;
            for (int i = r-1; i >= l; i--) { //then we craw along the last row going until left
                res.push_back(matrix[b-1][i]);
            }
            b--; //we dont need to consider bottom row
            for (int i = b-1; i >= t; i--) { //then we go up till we hit the top bound
                res.push_back(matrix[i][l]);
            }
            l++; //we dont need to consider first column
        }
        return res;
    }
};
