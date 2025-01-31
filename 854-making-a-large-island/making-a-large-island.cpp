class Solution {
private:
    int dfs(
        int row, 
        int col, 
        int landId,
        set<pair<int, int>>& vis, 
        vector<vector<int>>& grid
    ) {
        if(row < 0 || row == grid.size() || col < 0 || col == grid[0].size())
            return 0;
        
        if(grid[row][col] != 1 || vis.count({row, col})) return 0;
        
        vis.insert({row, col});

        int count = 1;

        grid[row][col] = landId;

        count += dfs(row-1, col, landId, vis, grid);
        count += dfs(row+1, col, landId, vis, grid);
        count += dfs(row, col-1, landId, vis, grid);
        count += dfs(row, col+1, landId, vis, grid);

        return count;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> vis;
        unordered_map<int, int> mp;
        int res = 0;

        int landId = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    mp[landId] = dfs(i, j, landId, vis, grid);
                    landId++;
                }
            }
        }

        if(!mp.size()) return 1;

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) {
                    unordered_set<int> visIsland;
                    for(int k = 0; k < 4; k++) {
                        int row = i + dir[k][0], col = j + dir[k][1];

                        if(row >= 0 && row < n && col >= 0 && col < n) {
                            int island = grid[row][col];

                            visIsland.insert(island);
                        }
                    }
                    int cnt  = 1;
                    for(int it:visIsland) cnt += mp[it];

                    res = max(res, cnt);
                }
            }
        }

        return res > 1 ? res : n * n;
    }
};