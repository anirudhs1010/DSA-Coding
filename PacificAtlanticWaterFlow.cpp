class Solution {
public:
    vector<vector<char>> flows; // Tracks flow status
    vector<vector<int>> res;    // Stores final results

    void floodFillP(vector<vector<int>>& heights, int i, int j) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || flows[i][j] == 'P') 
            return;
        
        flows[i][j] = 'P'; // Mark as reachable by Pacific

        // Explore neighbors
        if (i-1 >= 0 && heights[i][j] <= heights[i-1][j]) 
            floodFillP(heights, i-1, j);
        if (i+1 < heights.size() && heights[i][j] <= heights[i+1][j]) 
            floodFillP(heights, i+1, j);
        if (j-1 >= 0 && heights[i][j] <= heights[i][j-1]) 
            floodFillP(heights, i, j-1);
        if (j+1 < heights[0].size() && heights[i][j] <= heights[i][j+1]) 
            floodFillP(heights, i, j+1);
    }

    void floodFillA(vector<vector<int>>& heights, int i, int j) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || flows[i][j] == 'A') 
            return;

        if (flows[i][j] == 'P') 
            res.push_back({i, j}); // Add to result if reachable by Pacific

        flows[i][j] = 'A'; // Mark as reachable by Atlantic

        // Explore neighbors
        if (i-1 >= 0 && heights[i][j] <= heights[i-1][j]) 
            floodFillA(heights, i-1, j);
        if (i+1 < heights.size() && heights[i][j] <= heights[i+1][j]) 
            floodFillA(heights, i+1, j);
        if (j-1 >= 0 && heights[i][j] <= heights[i][j-1]) 
            floodFillA(heights, i, j-1);
        if (j+1 < heights[0].size() && heights[i][j] <= heights[i][j+1]) 
            floodFillA(heights, i, j+1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        flows.assign(m, vector<char>(n, 0)); // Initialize flows grid

        // Flood-fill for Pacific (top and left edges)
        for (int i = 0; i < m; i++) 
            floodFillP(heights, i, 0);
        for (int j = 0; j < n; j++) 
            floodFillP(heights, 0, j);

        // Flood-fill for Atlantic (bottom and right edges)
        for (int i = 0; i < m; i++) 
            floodFillA(heights, i, n-1);
        for (int j = 0; j < n; j++) 
            floodFillA(heights, m-1, j);

        return res;
    }
};
