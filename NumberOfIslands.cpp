class Solution {
public:
    //graph q just kinda annoying, bfs through every val that has 
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    // bfs here
                    queue<pair<int, int>> q; // store indexes
                    q.push({i, j});
                    grid[i][j] = '0'; // mark as visited by changing '1' to '0'
                    
                    while (!q.empty()) {
                        pair<int, int> a = q.front();
                        int r = a.first;
                        int c = a.second;
                        q.pop();
                        
                        // check all 4 directions
                        if (r+1 < grid.size() && grid[r+1][c] == '1') {
                            q.push({r+1, c});
                            grid[r+1][c] = '0'; // mark as visited
                        }
                        if (r-1 >= 0 && grid[r-1][c] == '1') {
                            q.push({r-1, c});
                            grid[r-1][c] = '0'; // mark as visited
                        }
                        if (c+1 < grid[0].size() && grid[r][c+1] == '1') {
                            q.push({r, c+1});
                            grid[r][c+1] = '0'; // mark as visited
                        }
                        if (c-1 >= 0 && grid[r][c-1] == '1') {
                            q.push({r, c-1});
                            grid[r][c-1] = '0'; // mark as visited
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
