class Solution {
public:
    unordered_set<string> s;
    vector<bool> visited; // Track used letters

    void backtrack(string &tiles, string ans) {
        if (!ans.empty()) 
            s.insert(ans); // Store non-empty sequences

        for (int i = 0; i < tiles.size(); i++) {
            // Skip if already used
            if (visited[i]) continue;
            
            // Skip duplicate letters (only if the previous duplicate was not used)
            if (i > 0 && tiles[i] == tiles[i-1] && !visited[i-1]) continue;

            // Mark as used and recurse
            visited[i] = true;
            backtrack(tiles, ans + tiles[i]);
            visited[i] = false; // Undo (backtrack)
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); // Sort to handle duplicates
        visited.resize(tiles.size(), false);
        backtrack(tiles, "");
        return s.size();
    }
};
