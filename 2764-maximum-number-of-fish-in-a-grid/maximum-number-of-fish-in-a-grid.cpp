class Solution {
private:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int dfs(int row, int col, int m, int n, vector<vector<int>>& grid) {
        if(!grid[row][col]) return 0;

        int cnt = grid[row][col];
        grid[row][col] = 0;

        for(int i = 0; i < 4; i++) {
            int rr = row + dir[i][0], cc = col + dir[i][1];

            if(isValid(rr, cc, m, n)) cnt += dfs(rr, cc, m, n, grid);
        }

        return cnt;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int res = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col]) {
                    res = max(res, dfs(row, col, m, n, grid));
                }
            }
        }

        return res;
    }
};