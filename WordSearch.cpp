class Solution {
public:
    
    bool backtrack(vector<vector<char>>& board, string word, int x, int y, int l) {
        if (l == word.size()) {
            return true;
        }
        if (y >= board[0].size() || x >= board.size() || x < 0 || y < 0 || board[x][y] != word[l])
            return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = backtrack(board, word, x+1, y, l+1) || backtrack(board, word, x, y+1, l+1)
        || backtrack(board, word, x-1, y, l+1) || backtrack(board, word, x, y-1, l+1);
        board[x][y] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
