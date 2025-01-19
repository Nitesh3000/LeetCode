class Solution {
private:
    void dfs(int r, int c, unordered_set<string>& visit, int prevHeight, vector<vector<int>>& heights, int rows, int cols) {
        string key = to_string(r) + "," + to_string(c);
        if (visit.count(key) || r < 0 || c < 0 || r == rows || c == cols || heights[r][c] < prevHeight) {
            return;
        }
        visit.insert(key);
        dfs(r + 1, c, visit, heights[r][c], heights, rows, cols);
        dfs(r - 1, c, visit, heights[r][c], heights, rows, cols);
        dfs(r, c + 1, visit, heights[r][c], heights, rows, cols);
        dfs(r, c - 1, visit, heights[r][c], heights, rows, cols);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        unordered_set<string> pac;
        unordered_set<string> atl;

        for (int c = 0; c < cols; c++) {
            dfs(0, c, pac, heights[0][c], heights, rows, cols);
            dfs(rows - 1, c, atl, heights[rows - 1][c], heights, rows, cols);
        }

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights[r][0], heights, rows, cols);
            dfs(r, cols - 1, atl, heights[r][cols - 1], heights, rows, cols);
        }

        vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                string key = to_string(r) + "," + to_string(c);
                if (pac.count(key) && atl.count(key)) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
