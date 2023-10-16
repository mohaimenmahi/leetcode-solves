class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool invalid(int row, int col, int n) {
        return row < 0 || col < 0 || row == n || col == n;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MIN));

        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                    vis.insert({i, j});
                }
            }
        }

        if(q.empty() || q.size() == n * n) return -1;

        int ans = INT_MIN;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int d = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for(int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];

                if(invalid(x, y, n) || grid[x][y] || vis.count({x, y})) continue;

                dist[x][y] = d + 1;
                q.push({dist[x][y], {x, y}});
                ans = max(ans, dist[x][y]);
                vis.insert({x, y});
            }
        }

        return ans;
    }
};