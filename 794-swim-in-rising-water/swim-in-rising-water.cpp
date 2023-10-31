class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = INT_MIN;

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        set<pair<int, int>> vis;

        pq.push({grid[0][0], {0, 0}});
        vis.insert({0, 0});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int t = top.first;
            int row = top.second.first;
            int col = top.second.second;

            ans = max(ans, t);
            
            if(row == n-1 && col == n-1) break;

            for(int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];

                if(x < 0 || y < 0 || x == n || y == n || vis.count({x, y}) > 0) continue;

                pq.push({grid[x][y], {x, y}});
                vis.insert({x, y});
            }
        }

        return ans;
    }
};