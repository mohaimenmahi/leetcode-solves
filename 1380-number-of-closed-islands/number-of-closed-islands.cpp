class Solution {
private:
    void markBoundary(int row, int col, int n, int m, vector<vector<int>>& grid) {
        if(row < 0 || col < 0 || row == n || col == m || grid[row][col]) return;

        grid[row][col] = 1;

        markBoundary(row + 1, col, n, m, grid);
        markBoundary(row - 1, col, n, m, grid);
        markBoundary(row, col + 1, n, m, grid);
        markBoundary(row, col - 1, n, m, grid);
    }
    void dfs(int row, int col, vector<vector<int>>& grid) {
        if(grid[row][col]) return;

        grid[row][col] = 1;
        
        bool res = true;

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            markBoundary(i, 0, n, m, grid);
            markBoundary(i, m-1, n, m, grid);
        }

        for(int j = 0; j < m; j++) {
            markBoundary(0, j, n, m, grid);
            markBoundary(n-1, j, n, m, grid);
        }
        
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};