class Solution {
public:
    bool visited[51][51];
    int c = 0;
    int y = 0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (c == 0) {
            y = image[sr][sc];
        }
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || visited[sr][sc])
            return image;
        else if (image[sr][sc] == color || image[sr][sc] != y) {
            return image;
        }
        image[sr][sc] = color;
        visited[sr][sc] = true;
        c++;
        
        floodFill(image, sr-1, sc, color);
        floodFill(image, sr+1, sc, color);
        floodFill(image, sr, sc-1, color);
        floodFill(image, sr, sc+1, color);
        return image;
    }
};
