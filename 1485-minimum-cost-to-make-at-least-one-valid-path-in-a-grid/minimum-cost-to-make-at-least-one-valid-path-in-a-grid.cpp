class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        cost[0][0] = 0;

        pq.push({0, 0, 0});

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int val = node[0], row = node[1], col = node[2];

            for(int i = 0; i < 4; i++) {
                int rr = row + dir[i][0], cc = col + dir[i][1];

                if(rr >= 0 && rr < rows && cc >= 0 && cc < cols) {
                    // if the current cell (row, col) directs to the
                    // expected neighbor:
                    // i+1 indicates the direction value, the dir array is
                    // mapped in the given direction values
                    int newCost = val + (i+1 != grid[row][col] ? 1 : 0);

                    if(newCost < cost[rr][cc]) {
                        cost[rr][cc] = newCost;
                        pq.push({newCost, rr, cc});
                    }
                }
            }
        }

        return cost[rows-1][cols-1];
    }
};