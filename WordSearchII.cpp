class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};
class Solution {
public:
    unordered_set<string> pos;
    vector<vector<bool>> visit;
    void dfs(vector<vector<char>>& board, string w, TrieNode* t, int r, int c) {
        if (r >= board.size() || c >= board[0].size() || r < 0 || c < 0 || 
        !t->children.count(board[r][c]) || visit[r][c]) {
            return;
        }
        
        visit[r][c] = true;
        t = t->children[board[r][c]];
        w += board[r][c];
        if (t->isWord)
            pos.insert(w);
        dfs(board, w, t, r+1, c);
        dfs(board, w, t, r, c+1);
        dfs(board, w, t, r-1, c);
        dfs(board, w, t, r, c-1);
        visit[r][c] = false;
    }
    //use tries to store words then use 
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }
        visit.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size();j++) {
                dfs(board, "", root, i, j);
            }
        }
        vector<string> s;
        for (const string a: pos)
            s.push_back(a);
        return s;

    }
};
