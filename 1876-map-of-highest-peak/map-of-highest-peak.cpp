class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> peaks(m, vector<int>(n, -1));

        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) {
                    q.push({0, {i, j}});
                    peaks[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int val = node.first, row = node.second.first, col = node.second.second;

            for(int i = 0; i < 4; i++) {
                int rr = row + dir[i][0], cc = col + dir[i][1];

                if(isValid(rr, cc, m, n) && peaks[rr][cc] == -1) {
                    peaks[rr][cc] = val + 1;
                    q.push({val+1, {rr, cc}});
                }
            }
        }

        return peaks;
    }
};