class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int trapRainWater(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > boundary;

        for(int i = 0; i < m; i++) {
            boundary.push({heights[i][0], {i, 0}});
            boundary.push({heights[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = 1;
        }

        for(int i = 1; i < n-1; i++) {
            boundary.push({heights[0][i],{0, i}});
            boundary.push({heights[m-1][i], {m-1, i}});
            visited[0][i] = visited[m-1][i] = 1;
        }

        int ans = 0;

        while(!boundary.empty()) {
            auto top = boundary.top();
            boundary.pop();

            int row = top.second.first, col = top.second.second, height = top.first;

            for(int i = 0; i < 4; i++) {
                int rr = row + dir[i][0], cc = col + dir[i][1];

                if(isValid(rr, cc, m, n) && !visited[rr][cc]) {
                    int neighborHeight = heights[rr][cc];

                    if(neighborHeight < height) {
                        ans += height - neighborHeight;
                    }

                    visited[rr][cc] = 1;
                    boundary.push({max(neighborHeight, height), {rr, cc}});
                }
            }
        }

        return ans;
    }
};