class Solution {
private:
    void dfs(
        int r,
        int c, 
        int m,
        int n,
        vector<vector<int>>& vis,
        vector<vector<int>>& heights,
        int prev
    ) {
        if(r < 0 || c < 0 || r == m || c == n || vis[r][c] || heights[r][c] < prev) return;

        vis[r][c] = 1;

        dfs(r-1, c, m, n, vis, heights, heights[r][c]);
        dfs(r+1, c, m, n, vis, heights, heights[r][c]);
        dfs(r, c+1, m, n, vis, heights, heights[r][c]);
        dfs(r, c-1, m, n, vis, heights, heights[r][c]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, pacific, heights, heights[i][0]);
            dfs(i, n-1, m, n, atlantic, heights, heights[i][n-1]);
        }

        for(int i = 0; i < n; i++) {
            dfs(0, i, m, n, pacific, heights, heights[0][i]);
            dfs(m-1, i, m, n, atlantic, heights, heights[m-1][i]);
        }

        vector<vector<int>> ans;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(pacific[r][c] == atlantic[r][c] && pacific[r][c] == 1) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};