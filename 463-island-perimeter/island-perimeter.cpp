typedef pair<int, int> pii;
class Solution {
private:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    bool isCount(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if(!isValid(r, c, m, n)) return true;

        if(grid[r][c] == 0) return true;

        return false;
    }

    void dfs(
        int r, 
        int c, 
        int m,
        int n, 
        vector<vector<int>>& grid, 
        int& ans, 
        set<pii>& vis
    ) {
        if(!isValid(r, c, m, n)) return;
        if(!grid[r][c]) return;
        if(vis.find({r, c}) != vis.end()) return;

        ans += isCount(r+1, c, m, n, grid);
        ans += isCount(r-1, c, m, n, grid);
        ans += isCount(r, c+1, m, n, grid);
        ans += isCount(r, c-1, m, n, grid);

        vis.insert({r, c});

        dfs(r+1, c, m, n, grid, ans, vis);
        dfs(r-1, c, m, n, grid, ans, vis);
        dfs(r, c+1, m, n, grid, ans, vis);
        dfs(r, c-1, m, n, grid, ans, vis);

    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<pii> vis;
        int ans = 0;

        bool flag = false;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, m, n, grid, ans, vis);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        return ans;
    }
};