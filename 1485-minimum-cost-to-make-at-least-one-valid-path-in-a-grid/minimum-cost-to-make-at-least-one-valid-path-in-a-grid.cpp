class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        cost[0][0] = 0;

        deque<vector<int>> dq;

        dq.push_front({0, 0});

        while(!dq.empty()) {
            auto front = dq.front();
            dq.pop_front();

            int row = front[0], col = front[1];

            for(int i = 0; i < 4; i++) {
                int rr = row + dir[i][0], cc = col + dir[i][1];
                int val = i+1 == grid[row][col] ? 0 : 1;

                if(rr >= 0 && rr < rows && cc >= 0 && cc < cols && cost[row][col] + val < cost[rr][cc]) {
                    cost[rr][cc] = cost[row][col] + val;

                    if(val == 1) {
                        dq.push_back({rr, cc});
                    } else {
                        dq.push_front({rr, cc});
                    }
                }
            }
        }

        return cost[rows-1][cols-1];
    }
};