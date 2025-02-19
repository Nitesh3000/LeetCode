class Solution {
private:
    void permutation(string& tiles, unordered_set<string>& set, int& count, int start) {
        if (start == tiles.size()) return;  // Base case
        
        for (int i = start; i < tiles.size(); i++) {
            swap(tiles[start], tiles[i]);
            
            if (set.find(tiles.substr(0, start + 1)) == set.end()) {
                set.insert(tiles.substr(0, start + 1));
                count++;
            }
            
            permutation(tiles, set, count, start + 1);
            swap(tiles[start], tiles[i]);  // Backtrack
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int count = 0;
        unordered_set<string> set;
        permutation(tiles, set, count, 0);
        return count;
    }
};
