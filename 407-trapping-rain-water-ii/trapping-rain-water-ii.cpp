class Solution {
private:
    class Cell {
    public:
        int height, row, col;

        Cell(int height, int row, int col): height(height), row(row), col(col) {}

        bool operator<(const Cell& other) const {
            // reverse comparison to simulate a minHeap
            return height >= other.height;
        }
    };
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int trapRainWater(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        priority_queue<Cell> boundary;

        for(int i = 0; i < m; i++) {
            boundary.push(Cell(heights[i][0], i, 0));
            boundary.push(Cell(heights[i][n-1], i, n-1));
            visited[i][0] = visited[i][n-1] = 1;
        }

        for(int i = 1; i < n-1; i++) {
            boundary.push(Cell(heights[0][i], 0, i));
            boundary.push(Cell(heights[m-1][i], m-1, i));
            visited[0][i] = visited[m-1][i] = 1;
        }

        int ans = 0;

        while(!boundary.empty()) {
            Cell top = boundary.top();
            boundary.pop();

            int row = top.row, col = top.col, height = top.height;

            for(int i = 0; i < 4; i++) {
                int rr = row + dir[i][0], cc = col + dir[i][1];

                if(isValid(rr, cc, m, n) && !visited[rr][cc]) {
                    int neighborHeight = heights[rr][cc];

                    if(neighborHeight < height) {
                        ans += height - neighborHeight;
                    }

                    visited[rr][cc] = 11;
                    boundary.push(Cell(max(neighborHeight, height), rr, cc));
                }
            }
        }

        return ans;
    }
};