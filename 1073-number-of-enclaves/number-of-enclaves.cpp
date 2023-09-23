class Solution {
private:
    void dfs(
        int row,
        int col,
        int m,
        int n,
        vector<vector<int>>& grid
    ) {
        if(row < 0 || row == m || col < 0 || col == n || !grid[row][col])
            return;

        grid[row][col] = 0;

        dfs(row+1, col, m, n, grid);
        dfs(row-1, col, m, n, grid);
        dfs(row, col+1, m, n, grid);
        dfs(row, col-1, m, n, grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, grid);
            dfs(i, n-1, m, n, grid);
        }

        for(int j = 0; j < n; j++) {
            dfs(0, j, m, n, grid);
            dfs(m-1, j, m, n, grid);
        }

        int ans = 0;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col]) ans++;
            }
        }

        return ans;
    }
};