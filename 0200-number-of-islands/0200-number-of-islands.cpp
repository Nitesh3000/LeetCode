class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int rows, int cols) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == '0') {
            return;
        }
        
        grid[x][y] = '0'; // Mark as visited
        
        //explore
        dfs(grid, x - 1, y, rows, cols); // up
        dfs(grid, x + 1, y, rows, cols); // down
        dfs(grid, x, y - 1, rows, cols); // left
        dfs(grid, x, y + 1, rows, cols); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j, rows, cols); 
                }
            }
        }
        
        return res;
    }
};
